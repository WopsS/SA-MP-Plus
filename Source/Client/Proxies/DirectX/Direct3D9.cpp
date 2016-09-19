#include <stdafx.hpp>
#include <Proxies/DirectX/Direct3D9.hpp>
#include <Proxies/DirectX/Direct3DDevice9.hpp>

Proxies::Direct3D9::Direct3D9(IDirect3D9* Original)
	: m_original(Original)
{
}

ULONG Proxies::Direct3D9::AddRef()
{
	return m_original->AddRef();
}

HRESULT Proxies::Direct3D9::CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
	return m_original->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
}

HRESULT Proxies::Direct3D9::CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
	return m_original->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
}

HRESULT Proxies::Direct3D9::CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
	return m_original->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
}

HRESULT Proxies::Direct3D9::CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
{
	return m_original->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
}

HRESULT Proxies::Direct3D9::CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
	return m_original->CheckDeviceType(Adapter, DeviceType, DisplayFormat, BackBufferFormat, Windowed);
}

HRESULT Proxies::Direct3D9::CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
{
	HRESULT Result = m_original->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);

	if (SUCCEEDED(Result))
	{
		*ppReturnedDeviceInterface = new Proxies::Direct3DDevice9(*ppReturnedDeviceInterface);
	}

	return Result;
}

HRESULT Proxies::Direct3D9::EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode)
{
	return m_original->EnumAdapterModes(Adapter, Format, Mode, pMode);
}

UINT Proxies::Direct3D9::GetAdapterCount()
{
	return m_original->GetAdapterCount();
}

HRESULT Proxies::Direct3D9::GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode)
{
	return m_original->GetAdapterDisplayMode(Adapter, pMode);
}

HRESULT Proxies::Direct3D9::GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier)
{
	return m_original->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
}

UINT Proxies::Direct3D9::GetAdapterModeCount(UINT Adapter, D3DFORMAT Format)
{
	return m_original->GetAdapterModeCount(Adapter, Format);
}

HMONITOR Proxies::Direct3D9::GetAdapterMonitor(UINT Adapter)
{
	return m_original->GetAdapterMonitor(Adapter);
}

HRESULT Proxies::Direct3D9::GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps)
{
	return m_original->GetDeviceCaps(Adapter, DeviceType, pCaps);
}

HRESULT Proxies::Direct3D9::QueryInterface(REFIID riid, void** ppvObject)
{
	auto Result = m_original->QueryInterface(riid, ppvObject);

	if (SUCCEEDED(Result) && riid == __uuidof(IDirect3D9))
	{
		*ppvObject = this;
	}

	return Result;
}

HRESULT Proxies::Direct3D9::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return m_original->RegisterSoftwareDevice(pInitializeFunction);
}

ULONG Proxies::Direct3D9::Release()
{
	auto Count = m_original->Release();

	if (Count == 0)
	{
		delete this;
	}

	return Count;
}
