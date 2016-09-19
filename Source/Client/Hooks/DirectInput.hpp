#pragma once

namespace Hooks
{
	namespace DirectInput
	{
		HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);

		void Hook();
	}
}