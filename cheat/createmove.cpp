
#include "createmove.h"
#include "usercmd.h"
#include "entity.h"
#include "entitylist.h"
#include "engine.h"
#include "settings.h"
#include "misc.h"
#include "../junk.h"

CreateMoveFn oCreateMove;

bool __fastcall hkCreateMove(void* self, void*, float flInputSampleTime, UserCmd* cmd)
{
	oCreateMove(self, flInputSampleTime, cmd);

	Entity* local = engine->GetLocal();

	JUNK(cmove1);

	if (!local || !cmd || cmd && !cmd->command_number)
		return false;

	JUNK(cmove2);

	misc.CreateMove(cmd);

	JUNK(cmove4);

	return false;
}
