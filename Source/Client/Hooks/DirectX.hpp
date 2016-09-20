#pragma once

namespace Hooks
{
	namespace DirectX
	{
		namespace Private
		{
			typedef IDirect3D9*(WINAPI* Direct3DCreate9_t)(UINT);
			extern Direct3DCreate9_t Real;

			IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);
		}

		void Hook();
	}
}