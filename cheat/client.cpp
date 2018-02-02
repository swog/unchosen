
#include "client.h"
#include "vmt.h"

ClientClass* Client::GetAllClasses(void)
{
	typedef ClientClass*(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 8))(this);
}

Client* client = 0;
