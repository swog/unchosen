
#include "offsets.h"
#include "netvars.h"

Offsets::Offsets()
{
}

void Offsets::Init()
{
	m_fFlags = netvars.FindOffset("DT_BasePlayer", "m_fFlags");
	m_vecViewOffset = netvars.FindOffset("DT_BasePlayer", "m_vecViewOffset[0]");
	m_iTeamNum = netvars.FindOffset("DT_BaseEntity", "m_iTeamNum");
}

Offsets offsets;
