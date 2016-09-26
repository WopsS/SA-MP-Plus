#pragma once

namespace Hooks
{
	namespace DirectInput
	{
		namespace Private
		{
			using real_t =  HRESULT(WINAPI*)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
			extern real_t Real;

			HRESULT WINAPI DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);
		}

		void Create();

		void Remove();
	}
}