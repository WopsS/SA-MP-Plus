#include <stdafx.hpp>
#include <Natives/Natives.hpp>

std::vector<AMX_NATIVE_INFO> Natives::List = 
{
	{ "IsUsingSampPlus", Natives::IsUsingSampPlus }
};

cell AMX_NATIVE_CALL Natives::IsUsingSampPlus(AMX* Amx, cell* Params)
{
	return PlayerManager::GetInstance()->Exists(static_cast<uint16_t>(Params[1]));
}
