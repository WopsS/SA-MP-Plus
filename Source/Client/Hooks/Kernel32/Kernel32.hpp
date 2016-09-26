#pragma once

namespace Hooks
{
	namespace Kernel32
	{
		namespace Private
		{
			namespace ExitProcess
			{
				using real_t = void(WINAPI*)(UINT ExitCode);
				extern real_t Real;

				void WINAPI Run(UINT ExitCode);
			}
		}

		void Create();

		void Remove();
	}
}