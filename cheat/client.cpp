
#include "client.h"
#include "vmt.h"
#include "../junk.h"

ClientClass* Client::GetAllClasses(void)
{
	JUNK(classes);
	typedef ClientClass*(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 8))(this);
}

Client* client = 0;
