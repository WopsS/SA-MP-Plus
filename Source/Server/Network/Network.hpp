#pragma once

class Network : public Singleton<Network>, public Peer
{
public:

	void CloseConnection(const RakNet::SystemAddress& Address, const bool SendNotification, const uint8_t OrderingChannel = 0, const PacketPriority Priority = LOW_PRIORITY);

	void Process();

	const bool Startup();

private:

	friend class Singleton<Network>;

	Network();
	~Network() = default;

	void OnConnected(const packet_t Packet);

	void OnConnectionLost(const rakpacket_t Packet);

	void OnIncomingConnection(const rakpacket_t Packet);

	bool m_running;
};