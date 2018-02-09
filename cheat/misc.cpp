
#include "misc.h"
#include "usercmd.h"
#include "settings.h"
#include "../junk.h"

void Misc::CreateMove(UserCmd* cmd)
{
	JUNK(misc1);
	if (settings.m_bAutohop && cmd->buttons & IN_JUMP && !local->IsOnGround())
	{
		JUNK(misc2);
		cmd->buttons &= ~IN_JUMP;
	}
}

Misc misc;
