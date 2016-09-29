#include <SharedLib.hpp>
#include <PlusNet/Packets/Client/PlayerInitialize.hpp>

Packets::PlayerInitialize::PlayerInitialize(const std::string& Name)
	: Name(Name)
{
}

void Packets::PlayerInitialize::Deserialize(RakNet::BitStream& BitStream)
{
	RakNet::RakString RakString;

	BitStream.Read(RakString);
	BitStream.Read(Version);

	Name = RakString.C_String();
}

void Packets::PlayerInitialize::Serialize(RakNet::BitStream& BitStream)
{
	BitStream.Write(RakNet::RakString(Name.c_str()));
	BitStream.Write(Version);
}
