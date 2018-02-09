
#include "createmove.h"
#include "usercmd.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "settings.h"
#include "../junk.h"

CreateMoveFn oCreateMove;

bool __fastcall hkCreateMove(void* self, void*, float flInputSampleTime, UserCmd* cmd)
{
	oCreateMove(self, flInputSampleTime, cmd);

	Entity* local = entitylist->GetEntity(engine->GetLocalPlayer());

	JUNK(cmove1);

	if (!local || !cmd || cmd && !cmd->command_number)
		return false;

	JUNK(cmove2);

	if (cmd->buttons & IN_JUMP && !local->IsOnGround())
	{
		JUNK(cmove3);
		cmd->buttons &= ~IN_JUMP;
	}

	JUNK(cmove4);

	return false;
}
