#include <stdafx.hpp>
#include <Hooks/DirectInput/DirectInput.hpp>
#include <Hooks/DirectX/DirectX.hpp>
#include <Hooks/Game/HUD.hpp>
#include <Hooks/Kernel32/Kernel32.hpp>

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

			// Command lines from SA-MP:
			//		- "-c" - starts the multiplayer game.
			//		- "-d" - starts the game in debug mode.
			// If we have "-c" argument in command line we do our things.
			if (SharedLib::Settings::GetInstance()->Exists("c") == true)
			{
				// Get path to "Documents" and set it to our logger.
				HRESULT Result = SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, DocumentsPath);

				// Set the log file path to "Documents\GTA San Andreas User Files" after we got "Documents" path with success.
				if (SUCCEEDED(Result))
				{
					SharedLib::Logger::GetInstance(std::string(DocumentsPath) + "\\GTA San Andreas User Files\\samp_plus.log", false);
				}

				Hooks::Initialize();

				// Hook things for external libraries first.
				Hooks::DirectInput::Create();
				Hooks::DirectX::Create();
				Hooks::Kernel32::Create();

				// Hooks SA things.
				Hooks::Game::HUD::Create();
			}

			break;
		}
		case DLL_PROCESS_DETACH:
		{
			if (SharedLib::Settings::GetInstance()->Exists("c") == true)
			{
				// Unhooks SA things.
				Hooks::Game::HUD::Remove();

				// Unhook things for external libraries.
				Hooks::Kernel32::Remove();
				Hooks::DirectX::Remove();
				Hooks::DirectInput::Remove();

				Hooks::Uninitialize();

				// Release our stuffs since we unhooked everything.
				SharedLib::Logger::Release();
				SharedLib::Settings::Release();
			}

			break;
		}
	}

	return TRUE;
}