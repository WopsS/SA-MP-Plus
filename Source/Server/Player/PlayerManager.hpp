#pragma once

#include <Player/Player.hpp>

class PlayerManager : public Singleton<PlayerManager>
{
public:

	void Add(const std::string& Name, const RakNet::SystemAddress& Address);

	const bool Exists(const uint16_t Id) const;

	Player* Get(const std::string& Name) const;

	Player* Get(const uint16_t Id) const;

	void OnConnect(const uint16_t Id);

	void OnDisconnect(const uint16_t Id);

	void Remove(const RakNet::SystemAddress& Address);

private:

	friend class Singleton<PlayerManager>;

	PlayerManager();
	~PlayerManager() = default;

	std::list<std::unique_ptr<Player>> m_players;

	std::array<Player*, MAX_PLAYERS> m_ids;
};