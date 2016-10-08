#include <stdafx.hpp>
#include <Player/PlayerManager.hpp>

PlayerManager::PlayerManager()
{
	m_ids.fill(nullptr);
}

void PlayerManager::Add(const std::string& Name, const RakNet::SystemAddress& Address)
{
	// Check if we have a valid name and no-one is using that name.
	if (std::regex_match(Name, std::regex("^[a-zA-Z0-9\\$\\(\\)\\.=_\\[\\]]+$")) == true && (Name.length() >= 3 && Name.length() <= MAX_PLAYER_NAME) && Get(Name) == nullptr)
	{
		m_players.push_back(std::make_unique<Player>(Name, Address));
	}
	else
	{
		Network::GetInstance()->SendAndClose(RPCId::InvalidName, nullptr, PacketReliability::RELIABLE_ORDERED, Address);
	}
}

const bool PlayerManager::Exists(const uint16_t Id) const
{
	return m_ids[Id] != nullptr;
}

Player* PlayerManager::Get(const std::string& Name) const
{
	// Find the player with that name.
	auto Iterator = std::find_if(m_players.begin(), m_players.end(), [&Name](const std::unique_ptr<::Player>& Player)
	{
		return Player->GetName() == Name;
	});

	return Iterator != m_players.end() ? Iterator->get() : nullptr;
}

Player* PlayerManager::Get(const uint16_t Id) const
{
	return m_ids[Id];
}

void PlayerManager::Remove(const RakNet::SystemAddress& Address)
{
	// Remove the player from the list.
	m_players.remove_if([&Address](const std::unique_ptr<::Player>& Player)
	{
		return Player->GetAddress() == Address;
	});
}

void PlayerManager::OnConnect(const uint16_t Id)
{
	char Name[MAX_PLAYER_NAME + 1];
	sampgdk::GetPlayerName(Id, Name, MAX_PLAYER_NAME + 1);

	auto Player = Get(Name);

	if (Player != nullptr)
	{
		// Set the player id pointer to our player class.
		m_ids[Id] = Player;

		// Set the player id to match the sa-mp server id.
		m_ids[Id]->SetId(Id);

		auto AmxList = AmxManager::GetInstance()->GetList();

		for (auto Amx : AmxList)
		{
			int Index = -1;

			if (amx_FindPublic(Amx, "OnPlusPlayerConnect", &Index) == AMX_ERR_NONE)
			{
				amx_Push(Amx, static_cast<cell>(Id));
				amx_Exec(Amx, nullptr, Index);
			}
		}
	}
}

void PlayerManager::OnDisconnect(const uint16_t Id)
{
	if (m_ids[Id] != nullptr)
	{
		// Force the player to be disconnected. This way we will prevent the client to remain active on our server when it is changing the server internally with s0beit or another program.
		Network::GetInstance()->CloseConnection(m_ids[Id]->GetAddress(), true);

		// Set the id pointer to nullptr.
		m_ids[Id] = nullptr;

		// Remove the player from the list.
		m_players.remove_if([Id](const std::unique_ptr<::Player>& Player)
		{
			return Player->GetId() == Id;
		});
	}
}
