#include <stdafx.hpp>
#include <Hooks/DirectInput.hpp>
#include <Hooks/DirectX.hpp>
#include <Hooks/RunningScript.hpp>

BOOL APIENTRY DllMain(HMODULE Module, DWORD Reason, LPVOID Reserved)
{
	switch (Reason)
	{
		case DLL_PROCESS_ATTACH:
		{
			Hooks::Initialize();

			Hooks::DirectInput::Create();
			Hooks::DirectX::Create();
			Hooks::RunningScript::Create();

			break;
		}
		case DLL_PROCESS_DETACH:
		{
			Hooks::RunningScript::Remove();
			Hooks::DirectX::Remove();
			Hooks::DirectInput::Remove();

			Hooks::Uninitialize();

			break;
		}
	}

	return TRUE;
}