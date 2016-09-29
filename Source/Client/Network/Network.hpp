#pragma once

enum class ConnectionState : uint8_t
{
	Disconnected = 0,
	Connecting,
	Connected,
	Error
};

class Network : public Singleton<Network>, public Peer
{
public:

	const RakNet::ConnectionAttemptResult Connect();
	
	void Disconnect();

	const ConnectionState GetState() const;

	const bool IsConnected() const;

	void Process();

private:

	friend class Singleton<Network>;

	Network();
	~Network();

	void OnAlreadyConnected(const rakpacket_t Packet);

	void OnConnectionAccepted(const rakpacket_t Packet);

	void OnConnectionBanned(const rakpacket_t Packet);

	void OnConnectionFailed(const rakpacket_t Packet);

	void OnConnectionLost(const rakpacket_t Packet);

	void OnDisconnectionNotification(const rakpacket_t Packet);

	void OnInvalidPassword(const rakpacket_t Packet);

	void OnInvalidVersion(const packet_t Packet);

	void OnServerFull(const rakpacket_t Packet);

	void SetState(const ConnectionState State);

	ConnectionState m_connectionState;

	uint8_t m_connectionRetries;

	StopWatch<> m_stopWatch;
};