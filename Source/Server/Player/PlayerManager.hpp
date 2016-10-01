#pragma once

class PlayerManager : public Singleton<PlayerManager>
{
public:

	void Add(const std::string& Name, const RakNet::SystemAddress& Address);

	void Remove(const RakNet::SystemAddress& Address);

private:

	friend class Singleton<PlayerManager>;

	PlayerManager() = default;
	~PlayerManager() = default;
};