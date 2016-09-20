#include <stdafx.hpp>
#include <Hooks/RunningScript.hpp>

Hooks::RunningScript::Private::Process::Real_t Hooks::RunningScript::Private::Process::Real;

void __fastcall Hooks::RunningScript::Private::Process::Run(void** ecx)
{
	Hooks::RunningScript::Private::Process::Real(ecx);
}

void Hooks::RunningScript::Create()
{
	Hooks::Create((LPVOID)0x00469F00, &Hooks::RunningScript::Private::Process::Run, &Hooks::RunningScript::Private::Process::Real, true);
}

void Hooks::RunningScript::Remove()
{
	Hooks::Remove((LPVOID)0x00469F00);
}
