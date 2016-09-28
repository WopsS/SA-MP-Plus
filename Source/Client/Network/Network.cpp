#include <stdafx.hpp>
#include <Network/Network.hpp>

Network::Network()
	: m_connectionState(ConnectionState::Disconnected)
	, m_connectionRetries(0)
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
	auto Settings = Settings::GetInstance();
	auto Host = Settings->Get<std::string>("h");
	auto Port = Settings->Get<uint16_t>("pp");
	auto Password = Settings->Get<std::string>("z");

	LOG_INFO << "[connection] Connecting to " << Host << ":" << Port << "...";

	// Just in case we will get the real IP address from the DNS.
	if (Host.at(0) < '0' || Host.at(0) > '9')
	{
		char RealIP[65];

		RakNet::RakNetSocket2::DomainNameToIP(Host.c_str(), RealIP);
		Host = std::string(RealIP);
	}

	// Let's connect with 3 connection attempts sended after 500ms each. The timeout before "ID_CONNECTION_ATTEMPT_FAILED" is received is 3 * 500 = 1500 ms. Keep it low because we want to connect before SA-MP.
	return m_rakPeer->Connect(Host.c_str(), Settings->Get<uint16_t>("pp"), Password.length() > 0 ? Password.c_str() : nullptr, Settings->GetLength<size_t>("z"), nullptr, 0, 3, 500, 3000);
}

void Network::Disconnect()
{
	if (IsConnected() == true)
	{
		m_rakPeer->CloseConnection(m_rakPeer->GetSystemAddressFromIndex(0), true);
		SetState(ConnectionState::Disconnected);
	}
}

const ConnectionState Network::GetState() const
{
	return m_connectionState;
}

const bool Network::IsConnected() const
{
	return GetState() == ConnectionState::Connected;
}

void Network::Process()
{
	// TODO: Find a way to change the server if it is somehow changed (s0beit), don't hook something from "samp.dll".

	// Try to connect if we are not connected or we aren't connecting to the server.
	if (IsConnected() == false && GetState() != ConnectionState::Connecting)
	{
		if (m_stopWatch.IsRunning() == true)
		{
			// Let's connect one second later.
			if (m_stopWatch.Elapsed<std::chrono::seconds>() >= 1)
			{
				SetState(ConnectionState::Connecting);

				Connect();
				m_stopWatch.Restart();
			}
		}
		else
		{
			m_stopWatch.Start();
		}
	}

	Peer::Process();
}

void Network::OnAlreadyConnected(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] You are already connected to " << Packet->SystemAddress.ToString(true, ':') << ".";
}

void Network::OnConnectionAccepted(const rakpacket_t Packet)
{
	SetState(ConnectionState::Connected);
	m_connectionRetries = 0;

	m_stopWatch.Stop();

	LOG_INFO << "[connection] Connected to " << Packet->SystemAddress.ToString(true, ':') << ".";

	// TODO: Send the version to the server.

	// Send the name to the server.
	Send(RPCIds::Player_Initialize, Packet::Create<Packets::PlayerInitialize>(Settings::GetInstance()->Get<std::string>("n")), PacketReliability::RELIABLE_ORDERED, Packet->SystemAddress);
}

void Network::OnConnectionBanned(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] You are banned from the server.";
}

void Network::OnConnectionFailed(const rakpacket_t Packet)
{
	// Check if we reach the maximum retries, if yes unhook and release the memory.
	if (m_connectionRetries <= 30)
	{
		m_connectionRetries++;
		SetState(ConnectionState::Disconnected);

		LOG_INFO << "[connection] Server is not responding. Reconnecting...";
	}
	else
	{
		LOG_INFO << "[connection] The server doesn't use SA-MP+, the connection was aborted.";
		SetState(ConnectionState::Error);
	}
}

void Network::OnConnectionLost(const rakpacket_t Packet)
{
	SetState(ConnectionState::Disconnected);
	LOG_INFO << "[connection] Connection to the server has been lost. Reconnecting...";
}

void Network::OnDisconnectionNotification(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] Connection to the server was closed.";

	// The server notify us about "exit" command so we will disconnect from the server and don't reconnect again.
	Disconnect();
	SetState(ConnectionState::Error);
}

void Network::OnInvalidPassword(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] Invalid server password.";
	SetState(ConnectionState::Error);
}

void Network::OnServerFull(const rakpacket_t Packet)
{
	LOG_INFO << "[connection] Server is full.";
	SetState(ConnectionState::Error);
}

void Network::SetState(const ConnectionState State)
{
	m_connectionState = State;

	// If here is an error let's unhook our things.
	if (State == ConnectionState::Error)
	{
		Game::Release();
	}
}
