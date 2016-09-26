#include <SharedLib.hpp>
#include <PlusNet/Packets/RakPacket.hpp>

Packets::RakPacket::RakPacket(const RakNet::SystemAddress& Address)
{
	SystemAddress = Address;
}

void Packets::RakPacket::Deserialize(RakNet::BitStream& BitStream)
{
}

void Packets::RakPacket::Serialize(RakNet::BitStream& BitStream)
{
}
