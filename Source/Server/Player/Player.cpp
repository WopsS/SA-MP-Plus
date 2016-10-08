#include <stdafx.hpp>
#include <Player/Player.hpp>

Player::Player(const std::string& Name, const RakNet::SystemAddress& Address)
	: m_id(INVALID_PLAYER_ID)
	, m_name(Name)
	, m_address(Address)
{
	LOG_INFO << "[connection] " << m_name << " has joined the server (" << m_address.ToString(true, ':') << ").";
}

Player::~Player()
{
	LOG_INFO << "[connection] " << m_name << " left the server (" << m_address.ToString(true, ':') << ").";
}

const RakNet::SystemAddress& Player::GetAddress() const
{
	return m_address;
}

const uint16_t Player::GetId() const
{
	return m_id;
}

const std::string& Player::GetName() const
{
	return m_name;
}

void Player::SetId(const uint16_t Id)
{
	m_id = Id;
}
