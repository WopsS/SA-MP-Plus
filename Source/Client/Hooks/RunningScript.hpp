#pragma once

namespace Hooks
{
	namespace RunningScript
	{
		namespace Private
		{
			namespace Process
			{
				typedef void(__fastcall* Real_t)(void** ecx);
				extern Real_t Real;

				void __fastcall Run(void** ecx);
			}
		}

		void Create();

		void Remove();
	}
}