#pragma once

class Network : public Singleton<Network>, public Peer
{
public:

	const RakNet::ConnectionAttemptResult Connect();
	
	void Disconnect();

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

	void OnServerFull(const rakpacket_t Packet);

	bool m_connecting;
};