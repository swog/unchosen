
#include "panel.h"
#include "vmt.h"
#include "../junk.h"

const char* Panel::GetClassname(VPANEL vguiPanel)
{
	JUNK(classname);
	typedef const char*(__thiscall* Fn)(void*, VPANEL);
	return ((Fn)vmt.GetVirtual(this, 36))(this, vguiPanel);
}

Panel* panel = 0;
