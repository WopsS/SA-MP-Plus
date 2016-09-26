#pragma once

namespace Hooks
{
	namespace Game
	{
		namespace HUD
		{
			namespace Private
			{
				using real_t = int(WINAPIV*)();
				extern real_t Real;

				int WINAPIV Run();
			}

			void Create();

			void Remove();
		}
	}
}