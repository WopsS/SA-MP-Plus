#pragma once

namespace SharedLib
{
	namespace Packets
	{
		class RakPacket : public Packet
		{
		public:

			RakPacket(const RakNet::SystemAddress& Address);
			~RakPacket() = default;

		private:

			void Deserialize(RakNet::BitStream& BitStream);

			void Serialize(RakNet::BitStream& BitStream);
		};
	}
}

using rakpacket_t = std::shared_ptr<SharedLib::Packets::RakPacket>;