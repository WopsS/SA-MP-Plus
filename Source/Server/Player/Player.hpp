#pragma once

class Player
{
public:

	Player(const std::string& Name, const RakNet::SystemAddress& Address);
	~Player();

	const RakNet::SystemAddress& GetAddress() const;

	const uint16_t GetId() const;

	const std::string& GetName() const;

private:

	friend class PlayerManager;

	void SetId(const uint16_t Id);

	uint16_t m_id;

	std::string m_name;

	RakNet::SystemAddress m_address;
};