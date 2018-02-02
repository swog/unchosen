
#include "visuals.h"
#include "entity.h"
#include "settings.h"
#include "../junk.h"

void Visuals::PaintPlayer(Entity* ent)
{
	JUNK(player);
}

Visuals::Visuals(void)
{
	JUNK(visuals);
}

void Visuals::PaintTraverse(void)
{
	JUNK(paint);
}

Visuals visuals;
