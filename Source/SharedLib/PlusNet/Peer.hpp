#pragma once

#include <PlusNet/Packet.hpp>
#include <PlusNet/RPCId.hpp>
#include <RakNet/PacketLogger.h>
#include <RakNet/RakPeerInterface.h>

// Packets
#include <PlusNet/Packets/Client/PlayerInitialize.hpp>
#include <PlusNet/Packets/Server/InvalidVersion.hpp>
#include <PlusNet/Packets/RakPacket.hpp>

class Peer
{
public:

	Peer();
	virtual ~Peer();

	virtual void Process();

	void Send(const RPCId Id, const packet_t Packet, const PacketReliability Reliability, const RakNet::AddressOrGUID& SystemIdentifier, const bool Broadcast = false, const int8_t OrderingChannel = 0, const PacketPriority Priority = PacketPriority::HIGH_PRIORITY);

	void SendAndClose(const RPCId Id, const packet_t Packet, const PacketReliability Reliability, const RakNet::AddressOrGUID& SystemIdentifier, const bool Broadcast = false, const int8_t OrderingChannel = 0, const PacketPriority Priority = PacketPriority::HIGH_PRIORITY);

protected:

	template<typename TClass, typename TFunction>
	void RegisterMessageFunction(const DefaultMessageIDTypes Id, TClass Class, TFunction Function)
	{
		if (m_messageFunction.find(Id) == m_messageFunction.end())
		{
			m_messageFunction.emplace(Id, std::bind(Function, Class, std::placeholders::_1));
		}
		else
		{
			LOG_ERROR << "Message function with id " << Id << " (" << RakNet::PacketLogger::BaseIDTOString(Id) << ") is already registred.";
		}
	}

	template<typename TClass, typename TFunction>
	void RegisterRPCFunction(const RPCId Id, TClass Class, TFunction Function)
	{
		if (m_rpcFunction.find(Id) == m_rpcFunction.end())
		{
			m_rpcFunction.emplace(Id, std::bind(Function, Class, std::placeholders::_1));
		}
		else
		{
			LOG_ERROR << "Message function with id " << static_cast<uint32_t>(Id) << " is already registred.";
		}
	}

	RakNet::RakPeerInterface* m_rakPeer;

private:

	std::vector<std::pair<RakNet::AddressOrGUID, StopWatch<std::chrono::high_resolution_clock>>> m_awaitingDisconnection;

	std::map<DefaultMessageIDTypes, std::function<void(const rakpacket_t)>> m_messageFunction;

	std::map<RPCId, std::function<void(const packet_t)>> m_rpcFunction;
};