#include <stdafx.hpp>
#include <Hooks/Hooks.hpp>

const bool Hooks::Initialize()
{
	return MH_Initialize() == MH_OK;
}

const bool Hooks::Uninitialize()
{
	return MH_Uninitialize() == MH_OK;
}

const MH_STATUS Hooks::Remove(LPVOID Target)
{
	return MH_RemoveHook(Target);
}

const MH_STATUS Hooks::Remove(const std::wstring& Module, const std::string& Name)
{
	LPVOID Target = nullptr;
	auto ModuleHandle = GetModuleHandle(Module.c_str());

	if (ModuleHandle != nullptr)
	{
		Target = (LPVOID)GetProcAddress(ModuleHandle, Name.c_str());
	}

	return Remove(Target);
}
