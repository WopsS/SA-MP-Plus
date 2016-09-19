#pragma once

namespace Hooks
{
	namespace DirectX
	{
		IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);

		void Hook();
	}
}