
#include "entitylist.h"
#include "vmt.h"

Entity* EntityList::GetEntity(int i)
{
	typedef Entity*(__thiscall* Fn)(void*, int);
	return ((Fn)vmt.GetVirtual(this, 3))(this, i);
}

Entity* EntityList::GetEntityFromHandle(EntityHandle handle)
{
	typedef Entity*(__thiscall* Fn)(void*, EntityHandle);
	return ((Fn)vmt.GetVirtual(this, 4))(this, handle);
}

int EntityList::GetHighestEntityIndex(void)
{
	typedef int(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 6))(this);
}

EntityList* entitylist = 0;
