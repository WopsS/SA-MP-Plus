#pragma once

#include <PlusNet/Packet.hpp>
#include <PlusNet/RPCIds.hpp>
#include <RakNet/PacketLogger.h>
#include <RakNet/RakPeerInterface.h>

// Packets
#include <PlusNet/Packets/PlayerInitialize.hpp>
#include <PlusNet/Packets/RakPacket.hpp>

namespace SharedLib
{
	class Peer
	{
	public:

		Peer();
		virtual ~Peer();

		virtual void Process();

		void Send(const RPCIds Id, const packet_t Packet, const PacketReliability Reliability, const RakNet::AddressOrGUID& SystemIdentifier, const bool Broadcast = false, const int8_t OrderingChannel = 0, const PacketPriority Priority = PacketPriority::HIGH_PRIORITY);

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
		void RegisterRPCFunction(const RPCIds Id, TClass Class, TFunction Function)
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

		bool m_running;

		RakNet::RakPeerInterface* m_rakPeer;

	private:

		std::map<DefaultMessageIDTypes, std::function<void(const rakpacket_t)>> m_messageFunction;

		std::map<RPCIds, std::function<void(const packet_t)>> m_rpcFunction;
	};
}