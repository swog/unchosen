
#include "misc.h"
#include "usercmd.h"
#include "settings.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "../junk.h"

void Misc::CreateMove(UserCmd* cmd)
{
	Entity* local = engine->GetLocal();

	JUNK(misc1);
	if (settings.m_bAutohop && cmd->buttons & IN_JUMP && !local->IsOnGround())
	{
		JUNK(misc2);
		cmd->buttons &= ~IN_JUMP;
	}
}

Misc misc;
