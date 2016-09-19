#include <stdafx.hpp>
#include <Hooks/DirectInput.hpp>
#include <Proxies/DirectInput/DirectInput8.hpp>

typedef HRESULT(WINAPI* DirectInput8Create_t)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
DirectInput8Create_t DirectInput8CreateReal;

HRESULT WINAPI Hooks::DirectInput::DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	auto Result = DirectInput8CreateReal(hinst, dwVersion, riidltf, ppvOut, punkOuter);

	if (SUCCEEDED(Result))
	{
		*ppvOut = new Proxies::DirectInput8(static_cast<IDirectInput8*>(*ppvOut));
	}

	return Result;
}

void Hooks::DirectInput::Hook()
{
	Hooks::Create(L"dinput8", "DirectInput8Create", &Hooks::DirectInput::DirectInput8Create, &DirectInput8CreateReal, true);
}
