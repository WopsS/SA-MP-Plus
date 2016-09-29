#include <SharedLib.hpp>
#include <PlusNet/Packets/Server/InvalidVersion.hpp>

void Packets::InvalidVersion::Deserialize(RakNet::BitStream& BitStream)
{
	RakNet::RakString RakString;
	BitStream.Read(RakString);

	Version = RakString.C_String();
}

void Packets::InvalidVersion::Serialize(RakNet::BitStream& BitStream)
{
	BitStream.Write(RakNet::RakString(Version.c_str()));
}
