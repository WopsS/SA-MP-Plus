#pragma once

namespace Proxies
{
	class DirectInput8 : public IDirectInput8
	{
	public:

		DirectInput8(IDirectInput8* Original);
		virtual ~DirectInput8() = default;

		ULONG __stdcall AddRef();

		HRESULT __stdcall ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMS lpdiCDParams, DWORD dwFlags, LPVOID pvRefData);

		HRESULT __stdcall CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8* lplpDirectInputDevice, LPUNKNOWN pUnkOuter);

		HRESULT __stdcall EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags);

		HRESULT __stdcall EnumDevicesBySemantics(LPCTSTR ptszUserName, LPDIACTIONFORMAT lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCB lpCallback, LPVOID pvRef, DWORD dwFlags);

		HRESULT __stdcall FindDevice(REFGUID rguidClass, LPCTSTR ptszName, LPGUID pguidInstance);

		HRESULT __stdcall GetDeviceStatus(REFGUID rguidInstance);

		HRESULT __stdcall Initialize(HINSTANCE hinst, DWORD dwVersion);

		HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);

		ULONG __stdcall Release();

		HRESULT __stdcall RunControlPanel(HWND hwndOwner, DWORD dwFlags);

	private:

		IDirectInput8* m_original;
	};
}