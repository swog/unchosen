
#include <Windows.h>
#include "vmt.h"
#include "surface.h"
#include "panel.h"
#include "painttraverse.h"
#include "../junk.h"

DWORD WINAPI ThreadCharter(LPVOID lpParameter)
{
	JUNK(charter);
	
	surface = (Surface*)vmt.GetInterfaceVersion("vguimatsurface.dll", "VGUI_Surface");
	panel = (Panel*)vmt.GetInterfaceVersion("vgui2.dll", "VGUI_Panel");
	
	oPaintTraverse = (PaintTraverseFn)vmt.HookVirtual(panel, 41, hkPaintTraverse);
	
	FreeLibraryAndExitThread((HMODULE)lpParameter, 0);
	return 0;
}

BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hInstDll);
		CreateThread(0, 0, ThreadCharter, 0, 0, 0);
		return TRUE;
	}
	
	return FALSE;
}
