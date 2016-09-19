#include <stdafx.hpp>

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK | SUPPORTS_VERSION;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** Data)
{
	sampgdk::logprintf("  SA-MP+: v%s successfully loaded.", SAMP_PLUS_VERSION);
	return sampgdk::Load(Data);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
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
}