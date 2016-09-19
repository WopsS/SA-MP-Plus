#pragma once

namespace Proxies
{
	class DirectInputDevice8 : public IDirectInputDevice8
	{
	public:

		DirectInputDevice8(IDirectInputDevice8* Original);
		virtual ~DirectInputDevice8() = default;

		HRESULT __stdcall Acquire();

		ULONG __stdcall AddRef();

		HRESULT __stdcall BuildActionMap(LPDIACTIONFORMAT lpdiaf, LPCTSTR lpszUserName, DWORD dwFlags);

		HRESULT __stdcall CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT* ppdeff, LPUNKNOWN punkOuter);

		HRESULT __stdcall EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl);

		HRESULT __stdcall EnumEffects(LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType);

		HRESULT __stdcall EnumEffectsInFile(LPCWSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags);

		HRESULT __stdcall EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags);

		HRESULT __stdcall Escape(LPDIEFFESCAPE pesc);

		HRESULT __stdcall GetCapabilities(LPDIDEVCAPS lpDIDevCaps);

		HRESULT __stdcall GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags);

		HRESULT __stdcall GetDeviceInfo(LPDIDEVICEINSTANCE pdidi);

		HRESULT __stdcall GetDeviceState(DWORD cbData, LPVOID lpvData);

		HRESULT __stdcall GetEffectInfo(LPDIEFFECTINFO pdei, REFGUID rguid);

		HRESULT __stdcall GetForceFeedbackState(LPDWORD pdwOut);

		HRESULT __stdcall GetImageInfo(LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader);

		HRESULT __stdcall GetObjectInfo(LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow);

		HRESULT __stdcall GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph);

		HRESULT __stdcall Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid);

		HRESULT __stdcall Poll();

		HRESULT __stdcall QueryInterface(REFIID riid, void** ppvObject);

		ULONG __stdcall Release();

		HRESULT __stdcall RunControlPanel(HWND hwndOwner, DWORD dwFlags);

		HRESULT __stdcall SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl);

		HRESULT __stdcall SendForceFeedbackCommand(DWORD dwFlags);

		HRESULT __stdcall SetActionMap(LPDIACTIONFORMATW lpdiActionFormat, LPCTSTR lptszUserName, DWORD dwFlags);

		HRESULT __stdcall SetCooperativeLevel(HWND hwnd, DWORD dwFlags);

		HRESULT __stdcall SetDataFormat(LPCDIDATAFORMAT lpdf);

		HRESULT __stdcall SetEventNotification(HANDLE hEvent);

		HRESULT __stdcall SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph);

		HRESULT __stdcall Unacquire();

		HRESULT __stdcall WriteEffectToFile(LPCWSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags);

	private:

		IDirectInputDevice8* m_original;
	};
}