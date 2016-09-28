#include <stdafx.hpp>
#include <Hooks/Game/HUD.hpp>

Hooks::Game::HUD::Private::real_t Hooks::Game::HUD::Private::Real;

void WINAPIV Hooks::Game::HUD::Private::Run()
{
	Network::GetInstance()->Process();

	if (Hooks::Game::HUD::Private::Real == nullptr)
	{
		// Assign the original value because we will use it once more before hook ended.
		Hooks::Game::HUD::Private::Real = (Hooks::Game::HUD::Private::real_t)0x0053E230;
		Network::Release();
	}

	Hooks::Game::HUD::Private::Real();
}

void Hooks::Game::HUD::Create()
{
	// Since SA-MP is using grahpics loop, we will use it too. 
	// Call order: SA-MP hook -> SA-MP+ hook -> graphics loop.
	// Note:
	//		Calling HUD::Draw() before SA-MP apply its own hooks:
	//				0053EB0D | E8 DE CD FC FF	| call gta_sa.50B8F0	|
	//				0053EB12 | E8 19 F7 FF FF	| call gta_sa.53E230	| HUD::Draw
	//				0053EB17 | EB 65			| jmp gta_sa.53EB7E		|
	//		after SA-MP apply its own hooks:
	//				0053EB0D | E8 DE CD FC FF	| call gta_sa.50B8F0	|
	//				0053EB12 | E8 C9 4E F0 03	| call samp.44439E0		| call HUD::Draw
	//				0053EB17 | EB 65			| jmp gta_sa.53EB7E		|
	Hooks::Create((LPVOID)0x0053E230, &Hooks::Game::HUD::Private::Run, &Hooks::Game::HUD::Private::Real, true);
}

void Hooks::Game::HUD::Remove()
{
	Hooks::Game::HUD::Private::Real = nullptr;
	Hooks::Remove((LPVOID)0x0053E230);
}
