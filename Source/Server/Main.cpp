#include <stdafx.hpp>

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK | SUPPORTS_VERSION;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** Data)
{
	// Add default values from "server.cfg" which we will use in our plugin.
	SharedLib::Settings::GetInstance()->Add("maxplayers", "50");
	SharedLib::Settings::GetInstance()->Add("announce", "0");
	SharedLib::Settings::GetInstance()->Add("query", "1");
	SharedLib::Settings::GetInstance()->Add("plusport", "8777");
	SharedLib::Settings::GetInstance()->Add("rcon_password", "changeme");
	SharedLib::Settings::GetInstance()->Add("password", "");
	SharedLib::Settings::GetInstance()->Add("bind", "");
	SharedLib::Settings::GetInstance()->Add("rcon", "1");
	SharedLib::Settings::GetInstance()->Add("timestamp", "1");
	SharedLib::Settings::GetInstance()->Add("logqueries", "0");

#ifdef WIN32 
	SharedLib::Settings::GetInstance()->Add("output", "1");
#else
	SharedLib::Settings::GetInstance()->Add("output", "0");
#endif

	SharedLib::Settings::GetInstance()->Add("messageholelimit", "3000");
	SharedLib::Settings::GetInstance()->Add("messageslimit", "500");
	SharedLib::Settings::GetInstance()->Add("ackslimit", "3000");
	SharedLib::Settings::GetInstance()->Add("playertimeout", "10000");
	SharedLib::Settings::GetInstance()->Add("minconnectiontime", "0");
	SharedLib::Settings::GetInstance()->Add("connseedtime", "300000");

	// Read "server.cfg" to overwrite our default values if needed.
	SharedLib::Settings::GetInstance()->Read("server.cfg", ' ', { "echo" });

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

	SharedLib::Logger::Release();
	SharedLib::Settings::Release();

	sampgdk::logprintf("  SA-MP+: Plugin unloaded.");
	sampgdk::Unload();
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx) 
{
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx) 
{
	return AMX_ERR_NONE;
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	Network::GetInstance()->Process();
}