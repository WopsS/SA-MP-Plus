#pragma once

namespace Hooks
{
	namespace DirectInput
	{
		namespace Private
		{
			typedef HRESULT(WINAPI* DirectInput8Create_t)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
			extern DirectInput8Create_t Real;

			HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);
		}

		void Create();

		void Remove();
	}
}