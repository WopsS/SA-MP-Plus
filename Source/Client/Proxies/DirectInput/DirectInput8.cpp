#include <stdafx.hpp>
#include <Proxies/DirectInput/DirectInput8.hpp>
#include <Proxies/DirectInput/DirectInputDevice8.hpp>

Proxies::DirectInput8::DirectInput8(IDirectInput8* Original)
	: m_original(Original)
{
}

ULONG Proxies::DirectInput8::AddRef()
{
	return m_original->AddRef();
}

HRESULT Proxies::DirectInput8::ConfigureDevices(LPDICONFIGUREDEVICESCALLBACK lpdiCallback, LPDICONFIGUREDEVICESPARAMS lpdiCDParams, DWORD dwFlags, LPVOID pvRefData)
{
	return m_original->ConfigureDevices(lpdiCallback, lpdiCDParams, dwFlags, pvRefData);
}

HRESULT Proxies::DirectInput8::CreateDevice(REFGUID rguid, LPDIRECTINPUTDEVICE8* lplpDirectInputDevice, LPUNKNOWN pUnkOuter)
{
	auto Result = m_original->CreateDevice(rguid, lplpDirectInputDevice, pUnkOuter);

	if (SUCCEEDED(Result))
	{
		*lplpDirectInputDevice = new DirectInputDevice8(*lplpDirectInputDevice);
	}

	return Result;
}

HRESULT Proxies::DirectInput8::EnumDevices(DWORD dwDevType, LPDIENUMDEVICESCALLBACK lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return m_original->EnumDevices(dwDevType, lpCallback, pvRef, dwFlags);
}

HRESULT Proxies::DirectInput8::EnumDevicesBySemantics(LPCTSTR ptszUserName, LPDIACTIONFORMAT lpdiActionFormat, LPDIENUMDEVICESBYSEMANTICSCB lpCallback, LPVOID pvRef, DWORD dwFlags)
{
	return m_original->EnumDevicesBySemantics(ptszUserName, lpdiActionFormat, lpCallback, pvRef, dwFlags);
}

HRESULT Proxies::DirectInput8::FindDevice(REFGUID rguidClass, LPCTSTR ptszName, LPGUID pguidInstance)
{
	return m_original->FindDevice(rguidClass, ptszName, pguidInstance);
}

HRESULT Proxies::DirectInput8::GetDeviceStatus(REFGUID rguidInstance)
{
	return m_original->GetDeviceStatus(rguidInstance);
}

HRESULT Proxies::DirectInput8::Initialize(HINSTANCE hinst, DWORD dwVersion)
{
	return m_original->Initialize(hinst, dwVersion);
}

HRESULT Proxies::DirectInput8::QueryInterface(REFIID riid, void** ppvObject)
{
	auto Result = m_original->QueryInterface(riid, ppvObject);

	if (SUCCEEDED(Result) && riid == IID_IDirectInput8)
	{
		*ppvObject = this;
	}

	return Result;
}

ULONG Proxies::DirectInput8::Release()
{
	auto Count = m_original->Release();

	if (Count == 0)
	{
		delete this;
	}

	return Count;
}

HRESULT Proxies::DirectInput8::RunControlPanel(HWND hwndOwner, DWORD dwFlags)
{
	return m_original->RunControlPanel(hwndOwner, dwFlags);
}
