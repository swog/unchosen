
#include "menu.h"
#include "surface.h"
#include "../junk.h"

void Menu::GetCursorPos(int& cx, int& cy)
{
	JUNK(cursorpos);
}

bool Menu::IsCursorOver(int x, int y, int w, int h)
{
	int mx, my;
	GetCursorPos(mx, my);
	return (mx > x) && (my > y) && (mx < x + w) && (my < y + h);
}

void Menu::DrawRect(int x0, int y0, int x1, int y1, Color col)
{
	surface->DrawSetColor(col);
	surface->DrawRect(x0, y0, x1, y1);
}

void Menu::DrawCheckBox(char* label, int x, int y, int w, int h, bool& setting)
{
	surface->DrawSetColor(m_CheckBoxColor);
	surface->DrawSetTextColor(Color(255, 255, 255, 255));
}

Menu::Menu(void)
{
	JUNK(menu);
}

void Menu::PaintTraverse(void)
{
	JUNK(paint);
}

Menu menu;
