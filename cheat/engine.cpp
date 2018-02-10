
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "vmt.h"
#include "../junk.h"

void Engine::GetScreenSize(int& sw, int& sh)
{
	JUNK(screen);
	typedef void(__thiscall* Fn)(void*, int&, int&);
	return ((Fn)vmt.GetVirtual(this, 5))(this, sw, sh);
}

bool Engine::GetPlayerInfo(int ent_num, player_info_t* pinfo)
{
	JUNK(info);
	typedef bool(__thiscall* Fn)(void*, int, player_info_t*);
	return ((Fn)vmt.GetVirtual(this, 8))(this, ent_num, pinfo);
}

int Engine::GetLocalPlayer(void)
{
	JUNK(local);
	typedef int(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 12))(this);
}

Entity* Engine::GetLocal()
{
	JUNK(local);
	return entitylist->GetEntity(engine->GetLocalPlayer());
}

void Engine::GetViewAngles(QAngle& va)
{
	JUNK(view);
	typedef void(__thiscall* Fn)(void*, QAngle&);
	return ((Fn)vmt.GetVirtual(this, 18))(this, va);
}

void Engine::SetViewAngles(QAngle& va)
{
	JUNK(view);
	typedef void(__thiscall* Fn)(void*, QAngle&);
	return ((Fn)vmt.GetVirtual(this, 19))(this, va);
}

bool Engine::IsInGame(void)
{
	JUNK(game);
	typedef bool(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 26))(this);
}

const matrix3x4_t& Engine::WorldToScreenMatrix(void)
{
	JUNK(projection);
	typedef const matrix3x4_t&(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 37))(this);
}

Engine* engine = 0;
