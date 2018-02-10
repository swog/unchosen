
#ifndef ENGINE_H
#define ENGINE_H

#include "vector.h"

class Entity;

struct player_info_t
{
private:
	char _0x0000[16];

public:
	char name[128]; //0x0010 
	int userid; //0x0090 
	char steamid[33]; //0x0094 

private:
	char _0x00B5[256];
};

class Engine
{
public:
	void GetScreenSize(int& sw, int& sh);
	bool GetPlayerInfo(int ent_num, player_info_t* pinfo);
	int GetLocalPlayer(void);
	Entity* GetLocal(void);
	void GetViewAngles(QAngle& va);
	void SetViewAngles(QAngle& va);
	bool IsInGame(void);
	const matrix3x4_t& WorldToScreenMatrix(void);
};

extern Engine* engine;

#endif
