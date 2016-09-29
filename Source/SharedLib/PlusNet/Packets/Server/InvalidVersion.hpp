#pragma once

namespace Packets
{
	class InvalidVersion : public Packet
	{
	public:

		InvalidVersion() = default;
		~InvalidVersion() = default;

		void Deserialize(RakNet::BitStream& BitStream);

		void Serialize(RakNet::BitStream& BitStream);

		std::string Version;
	};
}