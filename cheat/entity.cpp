
#include "entity.h"
#include "engine.h"

int Entity::entindex(void)
{
	return *(int*)(this + 0x64);
}

bool Entity::GetPlayerInfo(player_info_t* pinfo)
{
	return engine->GetPlayerInfo(entindex(), pinfo);
}
