
#ifndef ENTITY_H
#define ENTITY_H

struct player_info_t;

#define	FL_ONGROUND (1 << 0)

class Entity
{
public:
	int entindex(void);
	bool GetPlayerInfo(player_info_t* pinfo);
	const char* GetClassname(void);
	int GetFlags(void);
	bool IsOnGround(void);
};

#endif