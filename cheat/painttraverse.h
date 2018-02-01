
#ifndef PAINTTRAVERSE_H
#define PAINTTRAVERSE_H

#include "panel.h"

typedef void(__thiscall* PaintTraverseFn)(void*, VPANEL, bool, bool);
extern PaintTraverseFn oPaintTraverse;

void __fastcall hkPaintTraverse(void* self, void*, VPANEL vguiPanel, bool forceRepaint, bool allowForce = true);

#endif
