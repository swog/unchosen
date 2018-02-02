
#ifndef ENTITY_H
#define ENTITY_H

struct player_info_t;

class Entity
{
public:
	int entindex(void);
	bool GetPlayerInfo(player_info_t* pinfo);
};

#endif