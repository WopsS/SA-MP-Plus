#pragma once

namespace Proxies
{
	class Direct3D9 : public IDirect3D9
	{
	public:

		Direct3D9(IDirect3D9* Original);
		virtual ~Direct3D9() = default;

		ULONG __stdcall AddRef();

		HRESULT __stdcall CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat);

		HRESULT __stdcall CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat);

		HRESULT __stdcall CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat);

		HRESULT __stdcall CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels);

		HRESULT __stdcall CheckDeviceType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed);

		HRESULT __stdcall CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface);

		HRESULT __stdcall EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode);

		UINT __stdcall GetAdapterCount();

		HRESULT __stdcall GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode);

		HRESULT __stdcall GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier);

		UINT __stdcall GetAdapterModeCount(UINT Adapter, D3DFORMAT Format);

		HMONITOR __stdcall GetAdapterMonitor(UINT Adapter);

		HRESULT __stdcall GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps);

		HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);

		HRESULT __stdcall RegisterSoftwareDevice(void* pInitializeFunction);

		ULONG __stdcall Release();

	private:

		IDirect3D9* m_original;
	};
}