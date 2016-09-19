#include <stdafx.hpp>
#include <Hooks/DirectX.hpp>
#include <Proxies/DirectX/Direct3D9.hpp>

typedef IDirect3D9* (WINAPI* Direct3DCreate9_t)(UINT);
Direct3DCreate9_t Direct3DCreate9Real;

IDirect3D9* WINAPI Hooks::DirectX::Direct3DCreate9(UINT SDKVersion)
{
	auto IDirect3D9 = Direct3DCreate9Real(SDKVersion);
	auto Direct3D9 = new Proxies::Direct3D9(IDirect3D9);

	return Direct3D9;
}

void Hooks::DirectX::Hook()
{
	Hooks::Create(L"d3d9", "Direct3DCreate9", &Hooks::DirectX::Direct3DCreate9, &Direct3DCreate9Real, true);
}