
#include "offsets.h"
#include "netvars.h"

Offsets::Offsets()
{
}

void Offsets::Init()
{
	m_fFlags = netvars.FindOffsets("DT_BasePlayer", "m_fFlags");
}

Offsets offsets;
