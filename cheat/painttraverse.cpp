
#include "painttraverse.h"
#include "vmt.h"
#include "panel.h"
#include "surface.h"
#include "../junk.h"
#include "menu.h"
#include <cstring>

PaintTraverseFn oPaintTraverse;

void __fastcall hkPaintTraverse(void* self, void*, VPANEL vguiPanel, bool forceRepaint, bool allowForce)
{
	oPaintTraverse(self, vguiPanel, forceRepaint, allowForce);
	
	static VPANEL savedPanel = 0;
	if (!savedPanel)
	{
		if (!strcmp(panel->GetClassname(vguiPanel), "MatSystemTopPanel"))
		{
			savedPanel = vguiPanel;
		}
	}
	
	if (savedPanel != vguiPanel)
	{
		return;
	}
	
	menu.PaintTraverse();

}
