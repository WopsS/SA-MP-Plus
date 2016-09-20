#include <stdafx.hpp>
#include <Hooks/DirectX.hpp>
#include <Proxies/DirectX/Direct3D9.hpp>

Hooks::DirectX::Private::Direct3DCreate9_t Hooks::DirectX::Private::Real;

IDirect3D9* WINAPI Hooks::DirectX::Private::Direct3DCreate9(UINT SDKVersion)
{
	return new Proxies::Direct3D9(Real(SDKVersion));
}

void Hooks::DirectX::Create()
{
	Hooks::Create(L"d3d9", "Direct3DCreate9", &Hooks::DirectX::Private::Direct3DCreate9, &Hooks::DirectX::Private::Real, true);
}

void Hooks::DirectX::Remove()
{
	Hooks::Remove(L"d3d9", "Direct3DCreate9");
}
