#pragma once

class Network : public SharedLib::Singleton<Network>, public SharedLib::Peer
{
public:

	void Process();

	const bool Startup();

private:

	friend class SharedLib::Singleton<Network>;

	Network();
	~Network() = default;

	void OnConnected(const packet_t Packet);

	void OnConnectionLost(const rakpacket_t Packet);

	void OnIncomingConnection(const rakpacket_t Packet);
};