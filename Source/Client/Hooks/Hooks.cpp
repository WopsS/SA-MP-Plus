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