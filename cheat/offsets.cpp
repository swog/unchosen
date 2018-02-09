
#include "offsets.h"
#include "netvars.h"

Offsets::Offsets()
{
}

void Offsets::Init()
{
	m_fFlags = netvars.FindOffsets("DT_BasePlayer", "m_fFlags");
	m_vecViewOffset = netvars.FindOffset("DT_BasePlayer", "m_vecViewOffset[0]");
}

Offsets offsets;
