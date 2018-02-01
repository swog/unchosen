
#include "color.h"

typedef unsigned long HFont;

enum FontDrawType_t
{
	FONT_DRAW_DEFAULT = 0,
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,
	FONT_DRAW_TYPE_COUNT = 2,
};

enum EFontFlags
{
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800,
};

#ifdef CreateFont
#undef CreateFont
#endif

class Surface
{
public:
	void DrawSetColor(Color col);
	void DrawFilledRect(int x0, int y0, int x1, int y1);
	void DrawOutlinedRect(int x0, int y0, int x1, int y1);
	void DrawLine(int x0, int y0, int x1, int y1);
	
	void DrawSetTextFont(HFont font);
	void DrawSetTextColor(Color col);
	void DrawSetTextPos(int x, int y);
	void DrawPrintText(const wchar_t* text, int textLen, FontDrawType_t drawType = FONT_DRAW_DEFAULT);
	void DrawPrintText(const char* text, FontDrawType_t drawType = FONT_DRAW_DEFAULT);
	
	HFont CreateFont(void);
	bool SetFontGlyphSet(HFont font, const char* windowsFontName, int tall, int wide, int blur, int scanlines, int flags, int nRangeMin = 0, int nRangeMax = 0);
	void GetTextSize(HFont font, const wchar_t* text, int& wide, int& tall);
	void GetTextSize(HFont font, const char* text, int& wide, int& tall);
};

extern Surface* surface;
