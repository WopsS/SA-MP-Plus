#include <stdafx.hpp>
#include <Hooks/Kernel32/Kernel32.hpp>

Hooks::Kernel32::Private::ExitProcess::real_t Hooks::Kernel32::Private::ExitProcess::Real;

void WINAPI Hooks::Kernel32::Private::ExitProcess::Run(UINT ExitCode)
{
	Network::Release();
	Hooks::Kernel32::Private::ExitProcess::Real(ExitCode);
}

void Hooks::Kernel32::Create()
{
	// SA-MP will call "ExitProcess(0)" to close the game, so we will hook it in order to send our disconnect message to the server.
	// Call order: SA-MP -> our plugin -> real function.
	// Note: 
	//		I did this way because if we will take a look at the function Graphics::Render() before SA-MP apply its hooks we should see:
	//				0053EB0D | E8 DE CD FC FF       | call gta_sa.50B8F0		|
	//				0053EB12 | E8 19 F7 FF FF		| call gta_sa.53E230		| call Graphics::Render
	//				0053EB17 | EB 65				| jmp gta_sa.53EB7E			|
	//		and in Game::Shutdown():
	//				0053C900 | 56					| push esi					| Game::Shutdown
	//				0053C901 | 57					| push edi					|
	//				0053C902 | B9 40 42 BB 00		| mov ecx, gta_sa.BB4240	|
	//				0053C907 | E8 54 1D 06 00		| call gta_sa.59E660		|
	//		That's good, but after SA-MP apply its hooks it should look like this:
	//				0053EB0D | E8 DE CD FC FF       | call gta_sa.50B8F0		|
	//				0053EB12 | E8 C9 4E 24 04		| call samp.47839E0			| call Graphics::Render (by SA-MP)
	//				0053EB17 | EB 65				| jmp gta_sa.53EB7E			|
	//		and in Game::Shutdown():
	//				0053C900 | FF 25 F1 C8 53 00	| jmp dword ptr ds:[53C8F1]	| Game::Shutdown (by SA-MP)
	//				0053C906 | 90					| nop						|
	//				0053C907 | E8 54 1D 06 00		| call gta_sa.59E660		|
	//		so when a player execute "/q" command or close the game from the menu SA-MP will call "ExitProcess(0)" (as I said before).
	Hooks::Create(L"Kernel32", "ExitProcess", &Hooks::Kernel32::Private::ExitProcess::Run, &Hooks::Kernel32::Private::ExitProcess::Real, true);
}

void Hooks::Kernel32::Remove()
{
	Hooks::Remove(L"Kernel32", "ExitProcess");
}