#pragma once

namespace Hooks
{
	template<typename T>
	const MH_STATUS Create(void* Target, void* Detour, T** Original)
	{
		return MH_CreateHook(Target, Detour, reinterpret_cast<void*>(Original));
	}

	template<typename T>
	const MH_STATUS Create(const std::wstring& Module, const std::string& Name, void* Detour, T** Original, bool Enable)
	{
		return Create(Module, Name, Detour, Original, nullptr, Enable);
	}

	template<typename T>
	const MH_STATUS Create(const std::wstring& Module, const std::string& Name, void* Detour, T** Original, void** Target, bool Enable)
	{
		LoadLibrary(Module.c_str());

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
}