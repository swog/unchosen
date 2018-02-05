
#ifndef CREATEMOVE_H
#define CREATEMOVE_H

class UserCmd;

typedef bool(__thiscall* CreateMoveFn)(void* self, float flInputSampleTime, UserCmd* cmd);
extern CreateMoveFn oCreateMove;

bool __fastcall hkCreateMove(void* self, void*, float flInputSampleTime, UserCmd* cmd);

#endif
