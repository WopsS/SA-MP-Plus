#include <stdafx.hpp>
#include <Natives/Natives.hpp>

extern void* pAMXFunctions;

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerConnect(int Id)
{
	PlayerManager::GetInstance()->OnConnect(static_cast<uint16_t>(Id));
	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerDisconnect(int Id, int Reason)
{
	PlayerManager::GetInstance()->OnDisconnect(static_cast<uint16_t>(Id));
	return true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK | SUPPORTS_VERSION;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** Data)
{
	pAMXFunctions = Data[PLUGIN_DATA_AMX_EXPORTS];

	// Add default values from "server.cfg" which we will use in our plugin.
	Settings::GetInstance()->Add("maxplayers", "50");
	Settings::GetInstance()->Add("announce", "0");
	Settings::GetInstance()->Add("query", "1");
	Settings::GetInstance()->Add("plusport", "8777");
	Settings::GetInstance()->Add("rcon_password", "changeme");
	Settings::GetInstance()->Add("password", "");
	Settings::GetInstance()->Add("bind", "");
	Settings::GetInstance()->Add("rcon", "1");
	Settings::GetInstance()->Add("timestamp", "1");
	Settings::GetInstance()->Add("logqueries", "0");

#ifdef WIN32 
	Settings::GetInstance()->Add("output", "1");
#else
	Settings::GetInstance()->Add("output", "0");
#endif

	Settings::GetInstance()->Add("messageholelimit", "3000");
	Settings::GetInstance()->Add("messageslimit", "500");
	Settings::GetInstance()->Add("ackslimit", "3000");
	Settings::GetInstance()->Add("playertimeout", "10000");
	Settings::GetInstance()->Add("minconnectiontime", "0");
	Settings::GetInstance()->Add("connseedtime", "300000");

	// Read "server.cfg" to overwrite our default values if needed.
	Settings::GetInstance()->Read("server.cfg", ' ', { "echo" });

	if (Network::GetInstance()->Startup() == false)
	{
		return false;
	}

	// TODO: Add bans to our plugin.

	sampgdk::logprintf("  SA-MP+: v%s successfully loaded.", SAMP_PLUS_VERSION);
	return sampgdk::Load(Data);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	Network::Release();

	Logger::Release();
	Settings::Release();

	sampgdk::logprintf("  SA-MP+: Plugin unloaded.");
	sampgdk::Unload();
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* Amx)
{
	AmxManager::GetInstance()->Add(Amx);
	return amx_Register(Amx, Natives::List.data(), Natives::List.size());
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* Amx)
{
	AmxManager::GetInstance()->Remove(Amx);
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	Network::GetInstance()->Process();
}