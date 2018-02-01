
#include "surface.h"
#include "vmt.h"
#include "../junk.h"

typedef void(__thiscall* RepetitiveFn)(void*, int, int, int, int); 

void Surface::DrawSetColor(Color col)
{
	return ((RepetitiveFn)vmt.GetVirtual(15))(this, col.r(), col.g(), col.b(), col.a());
}

void Surface::DrawFilledRect(int x0, int y0, int x1, int y1)
{
	return ((RepetitiveFn)vmt.GetVirtual(16))(this, x0, y0, x1, y1);
}

void Surface::DrawOutlinedRect(int x0, int y0, int x1, int y1)
{
	return ((RepetitiveFn)vmt.GetVirtual(18))(this, x0, y0, x1, y1);
}

void Surface::DrawLine(int x0, int y0, int x1, int y1)
{
	return ((RepetitiveFn)vmt.GetVirtual(19))(this, x0, y0, x1, y1);
}

Surface* surface = 0;
