
#include "entity.h"
#include "engine.h"
#include "vmt.h"
#include "offsets.h"
#include "../junk.h"

int Entity::entindex(void)
{
	JUNK(index);
	return *(int*)(this + 0x64);
}

bool Entity::GetPlayerInfo(player_info_t* pinfo)
{
	JUNK(info);
	return engine->GetPlayerInfo(entindex(), pinfo);
}

const char* Entity::GetClassname(void)
{
	JUNK(classname);
	typedef const char*(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 139))(this);
}

int Entity::GetFlags(void)
{
	return *(int*)(this + offsets.m_fFlags);
}

bool Entity::IsOnGround(void)
{
	return GetFlags() & FL_ONGROUND;
}
