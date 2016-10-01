#include <stdafx.hpp>
#include <Player/PlayerManager.hpp>

void PlayerManager::Add(const std::string& Name, const RakNet::SystemAddress& Address)
{
	// Check if we have a valid name..
	if (std::regex_match(Name, std::regex("^[a-zA-Z0-9\\$\\(\\)\\.=_\\[\\]]+$")) == true && Name.length() >= 3 && Name.length() <= MAX_PLAYER_NAME)
	{
		LOG_INFO << "[connection] " << Name << " has joined the server (" << Address.ToString(true, ':') << ").";
	}
	else
	{
		Network::GetInstance()->SendAndClose(RPCId::InvalidName, nullptr, PacketReliability::RELIABLE_ORDERED, Address);
	}
}

void PlayerManager::Remove(const RakNet::SystemAddress& Address)
{
	LOG_INFO << "[connection] " << Address.ToString(true, ':') << " left the server.";
}
