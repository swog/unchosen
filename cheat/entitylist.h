
#ifndef ENTITYLIST_H
#define ENTITYLIST_H

class Entity;
typedef unsigned long EntityHandle;

class EntityList
{
public:
	Entity* GetEntity(int i);
	Entity* GetEntityFromHandle(EntityHandle handle);
	int GetHighestEntityIndex(void);
};

extern EntityList* entitylist;

#endif