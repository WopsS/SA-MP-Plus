#pragma once

namespace Natives
{
	extern std::vector<AMX_NATIVE_INFO> List;

	cell AMX_NATIVE_CALL IsUsingSampPlus(AMX* Amx, cell* Params);
}