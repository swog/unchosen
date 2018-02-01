
#include "painttraverse.h"
#include "vmt.h"
#include "panel.h"
#include "../junk.h"
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
}
