#include <stdafx.hpp>
#include <Network/Network.hpp>

Network::Network()
	: m_running(false)
{
	RegisterMessageFunction(ID_NEW_INCOMING_CONNECTION, this, &Network::OnIncomingConnection);
	RegisterMessageFunction(ID_DISCONNECTION_NOTIFICATION, this, &Network::OnConnectionLost);
	RegisterMessageFunction(ID_CONNECTION_LOST, this, &Network::OnConnectionLost);

	RegisterRPCFunction(RPCId::PlayerInitialize, this, &Network::OnConnected);
}

void Network::Process()
{
	if (m_running == true)
	{
		Peer::Process();
	}
}

const bool Network::Startup()
{
	auto Settings = Settings::GetInstance();

	auto Bind = Settings->Get<std::string>("bind");
	auto SocketDescriptor = RakNet::SocketDescriptor(Settings->Get<uint32_t>("plusport"), Bind.length() > 0 ? Bind.c_str() : nullptr);
	auto StartupResult = m_rakPeer->Startup(Settings->Get<uint32_t>("maxplayers"), &SocketDescriptor, 1);

	if (StartupResult != RakNet::StartupResult::RAKNET_STARTED)
	{
		LOG_ERROR << "[connectioin] Could not start the RakPeer, error " << StartupResult << ".";
	}
	else
	{
		auto Password = Settings->Get<std::string>("password");

		m_rakPeer->SetIncomingPassword(Password.c_str(), Password.length());
		m_rakPeer->SetTimeoutTime(Settings->Get<uint32_t>("playertimeout"), RakNet::UNASSIGNED_SYSTEM_ADDRESS);
		m_rakPeer->SetUnreliableTimeout(Settings->Get<uint32_t>("playertimeout"));
		m_rakPeer->SetMaximumIncomingConnections(Settings->Get<uint32_t>("maxplayers"));

		m_running = true;
	}

	return StartupResult == RakNet::StartupResult::RAKNET_STARTED;
}

void Network::OnConnected(const packet_t PlusPacket)
{
	// TODO: Check for a valid name (a-z, A-Z, 0-9).

	auto Packet = CONVERT_PACKET(PlusPacket, Packets::PlayerInitialize);

	if (Packet->Version == SAMP_PLUS_PROTOCOL_VERSION)
	{
		LOG_INFO << "[connection] " << Packet->Name << " has joined the server (" << Packet->SystemAddress.ToString(true, ':') << ").";
	}
	else
	{
		LOG_INFO << "[connection] Player " << Packet->Name << " is using an invalid version, connection closed (" << Packet->SystemAddress.ToString(true, ':') << ").";

		auto ReturnPacket = Packet::Create<Packets::InvalidVersion>();
		ReturnPacket->Version = SAMP_PLUS_VERSION;

		// Don't trust the client to close the connection.
		SendAndClose(RPCId::InvalidVersion, ReturnPacket, PacketReliability::RELIABLE_ORDERED, Packet->SystemAddress);
	}
}

void Network::OnConnectionLost(const rakpacket_t Packet)
{
	// TODO: Get player name.
	LOG_INFO << "[connection] " << Packet->SystemAddress.ToString(true, ':') << " left the server.";
}

void Network::OnIncomingConnection(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] incoming connection from " << Packet->SystemAddress.ToString(true, ':') << ".";
}