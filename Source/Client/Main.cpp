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
			char DocumentsPath[MAX_PATH], ExePath[MAX_PATH];

			// Remove "gta_sa.exe" path from name, the quoute marks and space before the first parameter.
			GetModuleFileName(GetModuleHandle("gta_sa.exe"), ExePath, _countof(ExePath));

			auto Settings = SharedLib::String::Split(std::string(GetCommandLine() + strlen(ExePath) + 3), '-');

			// Add default values.
			SharedLib::Settings::GetInstance()->Add("pp", "8777");

			// Process all settings from command line, overwrite our default values if needed.
			for (auto& i : Settings)
			{
				if (i.length() > 0)
				{
					SharedLib::Settings::GetInstance()->Process(i, ' ');
				}
			}

			// Get path to "Documents" and set it to our logger.
			HRESULT Result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, DocumentsPath);

			if (SUCCEEDED(Result))
			{
				SharedLib::Logger::GetInstance(std::string(DocumentsPath) + "\\GTA San Andreas User Files\\samp_plus.log", false);
			}

			// Hooks SA things.
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

			SharedLib::Logger::Release();
			SharedLib::Settings::Release();

			break;
		}
	}

	return TRUE;
}