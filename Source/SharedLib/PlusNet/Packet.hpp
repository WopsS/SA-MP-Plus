#pragma once

#include <RakNet/BitStream.h>
#include <RakNet/MessageIdentifiers.h>

enum DefaultMessageIDTypesEx
{
	ID_RPC = ID_USER_PACKET_ENUM
};

namespace SharedLib
{
	class Packet
	{
	public:

		Packet() = default;
		virtual ~Packet() = default;

		template<typename T, typename... Args>
		static std::shared_ptr<T> Create(Args&& ...args)
		{
			return std::make_shared<T>(std::forward<Args>(args)...);
		}

		virtual void Deserialize(RakNet::BitStream& BitStream) = 0;

		virtual void Serialize(RakNet::BitStream& BitStream) = 0;

		RakNet::SystemAddress SystemAddress;
	};
}

using packet_t = std::shared_ptr<SharedLib::Packet>;

#define CONVERT_PACKET(value, to) dynamic_cast<to*>(value.get())