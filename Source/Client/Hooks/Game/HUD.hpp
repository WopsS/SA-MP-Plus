#pragma once

namespace Hooks
{
	namespace Game
	{
		namespace HUD
		{
			namespace Private
			{
				using real_t = void(WINAPIV*)();
				extern real_t Real;

				void WINAPIV Run();
			}

			void Create();

			void Remove();
		}
	}
}