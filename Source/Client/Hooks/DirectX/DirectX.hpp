#pragma once

namespace Hooks
{
	namespace DirectX
	{
		namespace Private
		{
			using real_t = IDirect3D9*(WINAPI*)(UINT);
			extern real_t Real;

			IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);
		}

		void Create();

		void Remove();
	}
}