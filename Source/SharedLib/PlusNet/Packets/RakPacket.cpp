#include <SharedLib.hpp>
#include <PlusNet/Packets/RakPacket.hpp>

SharedLib::Packets::RakPacket::RakPacket(const RakNet::SystemAddress& Address)
{
	SystemAddress = Address;
}

void SharedLib::Packets::RakPacket::Deserialize(RakNet::BitStream& BitStream)
{
}

void SharedLib::Packets::RakPacket::Serialize(RakNet::BitStream& BitStream)
{
}
