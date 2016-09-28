#include <stdafx.hpp>
#include <Game/Game.hpp>
#include <Hooks/DirectInput/DirectInput.hpp>
#include <Hooks/DirectX/DirectX.hpp>
#include <Hooks/Game/HUD.hpp>
#include <Hooks/Kernel32/Kernel32.hpp>

Game::Game()
{
	Hooks::Initialize();

	// Hook things for external libraries first.
	Hooks::DirectInput::Create();
	Hooks::DirectX::Create();
	Hooks::Kernel32::Create();

	// Hooks SA things.
	Hooks::Game::HUD::Create();
}

Game::~Game()
{
	// Unhooks SA things.
	Hooks::Game::HUD::Remove();

	// Unhook things for external libraries.
	Hooks::Kernel32::Remove();
	Hooks::DirectX::Remove();
	Hooks::DirectInput::Remove();

	Hooks::Uninitialize();

	// Release our stuffs since we unhooked everything.
	// Note: Do not release the "Network" instance here because it will cause a dead-lock.
	Logger::Release();
	Settings::Release();
}
