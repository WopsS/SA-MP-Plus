#pragma once

namespace Hooks
{
	template<typename T>
	const MH_STATUS Create(void* Target, void* Detour, T** Original, bool Enable)
	{
		auto Result = MH_CreateHook(Target, Detour, reinterpret_cast<LPVOID*>(Original));

		if (Result == MH_OK)
		{
			Result = MH_EnableHook(Target);
		}

		return Result;
	}

	template<typename T>
	const MH_STATUS Create(const std::wstring& Module, const std::string& Name, void* Detour, T** Original, bool Enable)
	{
		return Create(Module, Name, Detour, Original, nullptr, Enable);
	}

	template<typename T>
	const MH_STATUS Create(const std::wstring& Module, const std::string& Name, void* Detour, T** Original, void** Target, bool Enable)
	{
		LoadLibraryW(Module.c_str());

		if (Enable == true)
		{
			bool WasNull = false;

			if (Target == nullptr)
			{
				Target = new void*;
				WasNull = true;
			}

			auto Result = MH_CreateHookApiEx(Module.c_str(), Name.c_str(), Detour, reinterpret_cast<LPVOID*>(Original), Target);

			if (Result == MH_OK)
			{
				Result = MH_EnableHook(*Target);
			}

			if (WasNull == true)
			{
				delete Target;
				Target = nullptr;
			}

			return Result;
		}
		else
		{
			return MH_CreateHookApiEx(Module.c_str(), Name.c_str(), Detour, reinterpret_cast<LPVOID*>(Original), Target);
		}
	}

	const bool Initialize();

	const bool Uninitialize();

	const MH_STATUS Remove(LPVOID Target);

	const MH_STATUS Remove(const std::wstring& Module, const std::string& Name);
}