#include <SharedLib.hpp>
#include <PlusNet/Packets/PlayerInitialize.hpp>

SharedLib::Packets::PlayerInitialize::PlayerInitialize(const std::string& Name)
	: Name(Name)
{
}

void SharedLib::Packets::PlayerInitialize::Deserialize(RakNet::BitStream& BitStream)
{
	RakNet::RakString RakString;
	BitStream.Read(RakString);

	Name = RakString.C_String();
}

void SharedLib::Packets::PlayerInitialize::Serialize(RakNet::BitStream& BitStream)
{
	BitStream.Write(RakNet::RakString(Name.c_str()));
}
