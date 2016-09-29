#pragma once

namespace Packets
{
	class RakPacket : public Packet
	{
	public:

		RakPacket() = default;
		RakPacket(const RakNet::SystemAddress& Address);

		~RakPacket() = default;

	private:

		void Deserialize(RakNet::BitStream& BitStream);

		void Serialize(RakNet::BitStream& BitStream);
	};
}

using rakpacket_t = std::shared_ptr<Packets::RakPacket>;
