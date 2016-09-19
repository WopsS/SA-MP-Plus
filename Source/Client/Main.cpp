#include <stdafx.hpp>

BOOL APIENTRY DllMain(HMODULE Module, DWORD Reason, LPVOID Reserved)
{
	switch (Reason)
	{
		case DLL_PROCESS_ATTACH:
		{
			Hooks::Initialize();

			break;
		}
		case DLL_PROCESS_DETACH:
		{
			Hooks::Uninitialize();

			break;
		}
	}

	return TRUE;
}