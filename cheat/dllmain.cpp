
#include <Windows.h>
#include "vmt.h"
#include "surface.h"
#include "../junk.h"

DWORD WINAPI ThreadCharter(LPVOID lpParameter)
{
	JUNK(charter);
	
	surface = vmt.GetInterfaceVersion("vguimatsurface.dll", "VGUI_Surface");
	
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
