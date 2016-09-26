#include <stdafx.hpp>
#include <Network/Network.hpp>

Network::Network()
	: m_connecting(false)
{
	m_rakPeer->Startup(1, &RakNet::SocketDescriptor(), 1, THREAD_PRIORITY_NORMAL);

	RegisterMessageFunction(ID_CONNECTION_REQUEST_ACCEPTED, this, &Network::OnConnectionAccepted);
	RegisterMessageFunction(ID_CONNECTION_ATTEMPT_FAILED, this, &Network::OnConnectionFailed);
	RegisterMessageFunction(ID_ALREADY_CONNECTED, this, &Network::OnAlreadyConnected);
	RegisterMessageFunction(ID_NO_FREE_INCOMING_CONNECTIONS, this, &Network::OnServerFull);
	RegisterMessageFunction(ID_DISCONNECTION_NOTIFICATION, this, &Network::OnDisconnectionNotification);
	RegisterMessageFunction(ID_CONNECTION_LOST, this, &Network::OnConnectionLost);
	RegisterMessageFunction(ID_CONNECTION_BANNED, this, &Network::OnConnectionBanned);
	RegisterMessageFunction(ID_INVALID_PASSWORD, this, &Network::OnInvalidPassword);
}

Network::~Network()
{
	Disconnect();
}

const RakNet::ConnectionAttemptResult Network::Connect()
{
	Disconnect();

	// TODO: Wait 3 seconds before another reconnect attempt.
	auto Settings = SharedLib::Settings::GetInstance();
	auto Host = Settings->Get<std::string>("h");
	auto Port = Settings->Get<uint16_t>("pp");
	auto Password = Settings->Get<std::string>("z");

	LOG_INFO << "[connection] Connecting to " << Host << ":" << Port << "...";

	return m_rakPeer->Connect(Host.c_str(), Settings->Get<uint16_t>("pp"), Password.length() > 0 ? Password.c_str() : nullptr, Settings->GetLength<size_t>("z"), nullptr, 0, 10, 500, 3000);
}

void Network::Disconnect()
{
	if (IsConnected() == true)
	{
		m_rakPeer->CloseConnection(m_rakPeer->GetSystemAddressFromIndex(0), true);
		m_running = false;
	}
}

const bool Network::IsConnected() const
{
	return m_running == true && m_connecting == false;
}

void Network::Process()
{
	// TODO: Find a way to change the server if it is somehow changed (s0beit), don't hook something from "samp.dll".

	// Try to connect if we are not connected or we aren't connecting to the server.
	if (m_running == false && m_connecting == false)
	{
		m_connecting = true;
		m_running = false;

		Connect();
	}

	SharedLib::Peer::Process();
}

void Network::OnAlreadyConnected(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] You are already connected to " << Packet->SystemAddress.ToString(true, ':') << ".";
}

void Network::OnConnectionAccepted(const rakpacket_t Packet)
{
	m_connecting = false;
	m_running = true;

	LOG_INFO << "[connection] Connected to " << Packet->SystemAddress.ToString(true, ':') << ".";

	// Send the name to the server.
	Send(RPCIds::Player_Initialize, SharedLib::Packet::Create<SharedLib::Packets::PlayerInitialize>(SharedLib::Settings::GetInstance()->Get<std::string>("n")), PacketReliability::RELIABLE_ORDERED, Packet->SystemAddress);
}

void Network::OnConnectionBanned(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] You are banned from the server.";
}

void Network::OnConnectionFailed(const rakpacket_t Packet)
{
	m_connecting = false;

	LOG_INFO << "[connection] Server is not responding. Reconnecting...";

	// TODO: Set a maximum number of retries before concluding that the server isn't using our plugin.
}

void Network::OnConnectionLost(const rakpacket_t Packet)
{
	m_running = false;

	LOG_INFO << "[connection] Connection to the server has been lost. Reconnecting...";
}

void Network::OnDisconnectionNotification(const rakpacket_t Packet)
{
	// The server notify us about "exit" command so we will disconnect from the server and don't reconnect again.
	Disconnect();
	m_connecting = true;

	LOG_INFO << "[connection] Connection to the server was closed.";
}

void Network::OnInvalidPassword(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] Invalid server password.";
}

void Network::OnServerFull(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] Server is full.";
}
