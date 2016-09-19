#include <stdafx.hpp>
#include <Proxies/DirectInput/DirectInputDevice8.hpp>

Proxies::DirectInputDevice8::DirectInputDevice8(IDirectInputDevice8* Original)
	: m_original(Original)
{
}

HRESULT Proxies::DirectInputDevice8::Acquire()
{
	return m_original->Acquire();
}

ULONG Proxies::DirectInputDevice8::AddRef()
{
	return m_original->AddRef();
}

HRESULT Proxies::DirectInputDevice8::BuildActionMap(LPDIACTIONFORMAT lpdiaf, LPCTSTR lpszUserName, DWORD dwFlags)
{
	return m_original->BuildActionMap(lpdiaf, lpszUserName, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::CreateEffect(REFGUID rguid, LPCDIEFFECT lpeff, LPDIRECTINPUTEFFECT* ppdeff, LPUNKNOWN punkOuter)
{
	return m_original->CreateEffect(rguid, lpeff, ppdeff, punkOuter);
}

HRESULT Proxies::DirectInputDevice8::EnumCreatedEffectObjects(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD fl)
{
	return m_original->EnumCreatedEffectObjects(lpCallback, pvRef, fl);
}

HRESULT Proxies::DirectInputDevice8::EnumEffects(LPDIENUMEFFECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwEffType)
{
	return m_original->EnumEffects(lpCallback, pvRef, dwEffType);
}

HRESULT Proxies::DirectInputDevice8::EnumEffectsInFile(LPCWSTR lpszFileName, LPDIENUMEFFECTSINFILECALLBACK pec, LPVOID pvRef, DWORD dwFlags)
{
	return m_original->EnumEffectsInFile(lpszFileName, pec, pvRef, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::EnumObjects(LPDIENUMDEVICEOBJECTSCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return m_original->EnumObjects(lpCallback, pvRef, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::Escape(LPDIEFFESCAPE pesc)
{
	return m_original->Escape(pesc);
}

HRESULT Proxies::DirectInputDevice8::GetCapabilities(LPDIDEVCAPS lpDIDevCaps)
{
	return m_original->GetCapabilities(lpDIDevCaps);
}

HRESULT Proxies::DirectInputDevice8::GetDeviceData(DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	return m_original->GetDeviceData(cbObjectData, rgdod, pdwInOut, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::GetDeviceInfo(LPDIDEVICEINSTANCE pdidi)
{
	return m_original->GetDeviceInfo(pdidi);
}

HRESULT Proxies::DirectInputDevice8::GetDeviceState(DWORD cbData, LPVOID lpvData)
{
	return m_original->GetDeviceState(cbData, lpvData);
}

HRESULT Proxies::DirectInputDevice8::GetEffectInfo(LPDIEFFECTINFO pdei, REFGUID rguid)
{
	return m_original->GetEffectInfo(pdei, rguid);
}

HRESULT Proxies::DirectInputDevice8::GetForceFeedbackState(LPDWORD pdwOut)
{
	return m_original->GetForceFeedbackState(pdwOut);
}

HRESULT Proxies::DirectInputDevice8::GetImageInfo(LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader)
{
	return m_original->GetImageInfo(lpdiDevImageInfoHeader);
}

HRESULT Proxies::DirectInputDevice8::GetObjectInfo(LPDIDEVICEOBJECTINSTANCE pdidoi, DWORD dwObj, DWORD dwHow)
{
	return m_original->GetObjectInfo(pdidoi, dwObj, dwHow);
}

HRESULT Proxies::DirectInputDevice8::GetProperty(REFGUID rguidProp, LPDIPROPHEADER pdiph)
{
	return m_original->GetProperty(rguidProp, pdiph);
}

HRESULT Proxies::DirectInputDevice8::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return m_original->Initialize(hinst, dwVersion, rguid);
}

HRESULT Proxies::DirectInputDevice8::Poll()
{
	return m_original->Poll();
}

HRESULT Proxies::DirectInputDevice8::QueryInterface(REFIID riid, void** ppvObject)
{
	auto Result = m_original->QueryInterface(riid, ppvObject);

	if (SUCCEEDED(Result) && riid == IID_IDirectInputDevice8)
	{
		*ppvObject = this;
	}

	return Result;
}

ULONG Proxies::DirectInputDevice8::Release()
{
	auto Count = m_original->Release();

	if (Count == 0)
	{
		delete this;
	}

	return Count;
}

HRESULT Proxies::DirectInputDevice8::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return m_original->RunControlPanel(hwndOwner, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::SendDeviceData(DWORD cbObjectData, LPCDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD fl)
{
	return m_original->SendDeviceData(cbObjectData, rgdod, pdwInOut, fl);
}

HRESULT Proxies::DirectInputDevice8::SendForceFeedbackCommand(DWORD dwFlags)
{
	return m_original->SendForceFeedbackCommand(dwFlags);
}

HRESULT Proxies::DirectInputDevice8::SetActionMap(LPDIACTIONFORMATW lpdiActionFormat, LPCTSTR lptszUserName, DWORD dwFlags)
{
	return m_original->SetActionMap(lpdiActionFormat, lptszUserName, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::SetCooperativeLevel(HWND hwnd, DWORD dwFlags)
{
	return m_original->SetCooperativeLevel(hwnd, dwFlags);
}

HRESULT Proxies::DirectInputDevice8::SetDataFormat(LPCDIDATAFORMAT lpdf)
{
	return m_original->SetDataFormat(lpdf);
}

HRESULT Proxies::DirectInputDevice8::SetEventNotification(HANDLE hEvent)
{
	return m_original->SetEventNotification(hEvent);
}

HRESULT Proxies::DirectInputDevice8::SetProperty(REFGUID rguidProp, LPCDIPROPHEADER pdiph)
{
	return m_original->SetProperty(rguidProp, pdiph);
}

HRESULT Proxies::DirectInputDevice8::Unacquire()
{
	return m_original->Unacquire();
}

HRESULT Proxies::DirectInputDevice8::WriteEffectToFile(LPCWSTR lpszFileName, DWORD dwEntries, LPDIFILEEFFECT rgDiFileEft, DWORD dwFlags)
{
	return m_original->WriteEffectToFile(lpszFileName, dwEntries, rgDiFileEft, dwFlags);
}