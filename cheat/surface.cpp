
#include <Windows.h>
#include "surface.h"
#include "vmt.h"
#include "../junk.h"

typedef void(__thiscall* RepetitiveFn)(void*, int, int, int, int); 

void Surface::DrawSetColor(Color col)
{
	return ((RepetitiveFn)vmt.GetVirtual(this, 15))(this, col.r(), col.g(), col.b(), col.a());
}

void Surface::DrawFilledRect(int x0, int y0, int x1, int y1)
{
	return ((RepetitiveFn)vmt.GetVirtual(this, 16))(this, x0, y0, x1, y1);
}

void Surface::DrawOutlinedRect(int x0, int y0, int x1, int y1)
{
	return ((RepetitiveFn)vmt.GetVirtual(this, 18))(this, x0, y0, x1, y1);
}

void Surface::DrawLine(int x0, int y0, int x1, int y1)
{
	return ((RepetitiveFn)vmt.GetVirtual(this, 19))(this, x0, y0, x1, y1);
}

void Surface::DrawSetTextFont(HFont font)
{
	typedef void(__thiscall* Fn)(void*, HFont);
	return ((Fn)vmt.GetVirtual(this, 23))(this, font);
}

void Surface::DrawSetTextColor(Color col)
{
	return ((RepetitiveFn)vmt.GetVirtual(this, 25))(this, col.r(), col.g(), col.b(), col.a());
}

void Surface::DrawSetTextPos(int x, int y)
{
	typedef void(__thiscall* Fn)(void*, int, int);
	return ((Fn)vmt.GetVirtual(this, 26))(this, x, y);
}

void Surface::DrawPrintText(const wchar_t* text, int textLen, FontDrawType_t drawType)
{
	typedef void(__thiscall* Fn)(void*, const wchar_t*, int, FontDrawType_t);
	return ((Fn)vmt.GetVirtual(this, 28))(this, text, textLen, drawType);
}

void Surface::DrawPrintText(const char* text, FontDrawType_t drawType)
{
	wchar_t wbuf[256];
	MultiByteToWideChar(CP_UTF8, 0, text, 256, wbuf, 256);
	DrawPrintText(wbuf, wcslen(wbuf), drawType);
}

HFont Surface::CreateFont(void)
{
	typedef HFont(__thiscall* Fn)(void*);
	return ((Fn)vmt.GetVirtual(this, 71))(this);
}

bool Surface::SetFontGlyphSet(HFont font, const char* windowsFontName, int tall, int wide, int blur, int scanlines, int flags, int nRangeMin, int nRangeMax)
{
	typedef bool(__thiscall* Fn)(void*, HFont, const char*, int, int, int, int, int, int, int);
	return ((Fn)vmt.GetVirtual(this, 72))(this, font, windowsFontName, tall, wide, blur, scanlines, flags, nRangeMin, nRangeMax);
}

void Surface::GetTextSize(HFont font, const wchar_t* text, int& wide, int& tall)
{
	typedef void(__thiscall* Fn)(void*, HFont, const wchar_t*, int&, int&);
	return ((Fn)vmt.GetVirtual(this, 79))(this, font, text, wide, tall);
}

void Surface::GetTextSize(HFont font, const char* text, int& wide, int& tall)
{
	wchar_t wbuf[256];
	MultiByteToWideChar(CP_UTF8, 0, text, 256, wbuf, 256);
	GetTextSize(font, wbuf, wide, tall);
}

Surface* surface = 0;
