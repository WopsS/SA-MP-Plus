#pragma once

namespace SharedLib
{
	namespace Packets
	{
		class PlayerInitialize : public Packet
		{
		public:

			PlayerInitialize() = default;
			PlayerInitialize(const std::string& Name);

			~PlayerInitialize() = default;

			void Deserialize(RakNet::BitStream& BitStream);

			void Serialize(RakNet::BitStream& BitStream);

			std::string Name;
		};
	}
}