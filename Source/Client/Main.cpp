#include <stdafx.hpp>
#include <Hooks/DirectInput.hpp>
#include <Hooks/DirectX.hpp>

BOOL APIENTRY DllMain(HMODULE Module, DWORD Reason, LPVOID Reserved)
{
	switch (Reason)
	{
		case DLL_PROCESS_ATTACH:
		{
			Hooks::Initialize();

			Hooks::DirectInput::Hook();
			Hooks::DirectX::Hook();

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