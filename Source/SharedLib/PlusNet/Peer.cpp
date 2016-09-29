#include <SharedLib.hpp>
#include <PlusNet/Peer.hpp>

Peer::Peer()
	: m_rakPeer(RakNet::RakPeerInterface::GetInstance())
{
	static_assert(sizeof(RPCId) == sizeof(uint8_t), "Size of RPCTypes is not equal with uint8_t");

	// TODO: Secure the network traffic.
}

Peer::~Peer()
{
	m_rakPeer->Shutdown(500);
	RakNet::RakPeerInterface::DestroyInstance(m_rakPeer);
}

void Peer::Process()
{
	if (m_awaitingDisconnection.empty() == false)
	{
		// Close all connections after 1 second.
		m_awaitingDisconnection.erase(std::remove_if(m_awaitingDisconnection.begin(), m_awaitingDisconnection.end(), [&](std::pair<RakNet::AddressOrGUID, Stopwatch<std::chrono::high_resolution_clock>>& Item)
		{ 
			bool ShouldRemove = false;
			auto& Stopwatch = Item.second;

			if (Stopwatch.IsRunning() == true)
			{
				if (Stopwatch.Elapsed<std::chrono::seconds>() >= 1)
				{
					m_rakPeer->CloseConnection(Item.first, false);
					ShouldRemove = true;
				}
			}
			else
			{
				Stopwatch.Start();
			}

			return ShouldRemove;
		}), m_awaitingDisconnection.end());
	}

	RakNet::Packet* RakPacket = nullptr;

	while ((RakPacket = m_rakPeer->Receive()) != nullptr)
	{
		RakNet::BitStream BitStream(RakPacket->data, RakPacket->length, false);

		uint8_t Type;
		BitStream.Read<uint8_t>(Type);

		if (Type == ID_RPC)
		{
			BitStream.Read<uint8_t>(Type);

			auto RPCId = static_cast<::RPCId>(Type);
			auto Map = m_rpcFunction.find(RPCId);

			if (Map != m_rpcFunction.end())
			{
				packet_t Packet = nullptr;

				switch (RPCId)
				{
					case ::RPCId::PlayerInitialize:
					{
						Packet = Packet::Create<Packets::PlayerInitialize>();
						break;
					}
					case ::RPCId::InvalidVersion:
					{
						Packet = Packet::Create<Packets::InvalidVersion>();
						break;
					}
				}

				Packet->SystemAddress = RakPacket->systemAddress;
				Packet->Deserialize(BitStream);

				Map->second(std::move(Packet));
			}
			else
			{
				LOG_WARNING << "[RPC] Unhandled RPC (id=" << static_cast<uint32_t>(RPCId) << ") with " << RakPacket->length << " bytes.";
			}
		}
		else
		{
			auto Function = m_messageFunction.find(static_cast<DefaultMessageIDTypes>(Type));

			if (Function != m_messageFunction.end())
			{
				Function->second(std::make_shared<Packets::RakPacket>(RakPacket->systemAddress));
			}
			else
			{
				LOG_WARNING << "[packet] Unhandled packet (id=" << static_cast<uint32_t>(Type) << ") with " << RakPacket->length << " bytes.";
			}
		}

		m_rakPeer->DeallocatePacket(RakPacket);
	}
}

void Peer::Send(const RPCId Id, const packet_t Packet, const PacketReliability Reliability, const RakNet::AddressOrGUID& SystemIdentifier, const bool Broadcast, const int8_t OrderingChannel, const PacketPriority Priority)
{
	RakNet::BitStream BitStream;

	BitStream.Write(static_cast<uint8_t>(ID_RPC));
	BitStream.Write(static_cast<uint8_t>(Id));

	if (Packet != nullptr)
	{
		Packet->Serialize(BitStream);
	}

	m_rakPeer->Send(&BitStream, Priority, Reliability, OrderingChannel, SystemIdentifier, Broadcast);
}

void Peer::SendAndClose(const RPCId Id, const packet_t Packet, const PacketReliability Reliability, const RakNet::AddressOrGUID& SystemIdentifier, const bool Broadcast, const int8_t OrderingChannel, const PacketPriority Priority)
{
	Send(Id, Packet, Reliability, SystemIdentifier, Broadcast, OrderingChannel, Priority);
	m_awaitingDisconnection.emplace_back(SystemIdentifier, Stopwatch<std::chrono::high_resolution_clock>());
}
