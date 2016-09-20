#include <stdafx.hpp>
#include <Hooks/DirectInput.hpp>
#include <Proxies/DirectInput/DirectInput8.hpp>

Hooks::DirectInput::Private::DirectInput8Create_t Hooks::DirectInput::Private::Real;

HRESULT WINAPI Hooks::DirectInput::Private::DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	auto Result = Real(hinst, dwVersion, riidltf, ppvOut, punkOuter);

	if (SUCCEEDED(Result))
	{
		*ppvOut = new Proxies::DirectInput8(static_cast<IDirectInput8*>(*ppvOut));
	}

	return Result;
}

void Hooks::DirectInput::Hook()
{
	Hooks::Create(L"dinput8", "DirectInput8Create", &Hooks::DirectInput::Private::DirectInput8Create, &Hooks::DirectInput::Private::Real, true);
}
