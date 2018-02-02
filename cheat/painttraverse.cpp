
#include "painttraverse.h"
#include "vmt.h"
#include "panel.h"
#include "surface.h"
#include "../junk.h"
#include "menu.h"
#include "visuals.h"
#include <cstring>

PaintTraverseFn oPaintTraverse;

void __fastcall hkPaintTraverse(void* self, void*, VPANEL vguiPanel, bool forceRepaint, bool allowForce)
{
	oPaintTraverse(self, vguiPanel, forceRepaint, allowForce);
	
	JUNK(paint1);

	static VPANEL savedPanel = 0;
	if (!savedPanel)
	{
		JUNK(paint2);
		if (!strcmp(panel->GetClassname(vguiPanel), "MatSystemTopPanel"))
		{
			savedPanel = vguiPanel;
		}
	}
	
	JUNK(paint3);

	if (savedPanel != vguiPanel)
	{
		return;
	}
	
	menu.PaintTraverse();
	visuals.PaintTraverse();
}
