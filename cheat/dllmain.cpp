
#include <Windows.h>
#include "vmt.h"
#include "surface.h"
#include "panel.h"
#include "painttraverse.h"
#include "entitylist.h"
#include "engine.h"
#include "client.h"
#include "netvars.h"
#include "createmove.h"
#include "clientmode.h"
#include "../junk.h"

DWORD WINAPI ThreadCharter(LPVOID lpParameter)
{
	JUNK(charter1);
	surface = (Surface*)vmt.GetInterfaceVersion("vguimatsurface.dll", "VGUI_Surface");
	panel = (Panel*)vmt.GetInterfaceVersion("vgui2.dll", "VGUI_Panel");
	JUNK(charter2);
	entitylist = (EntityList*)vmt.GetInterfaceVersion("client.dll", "VClientEntityList");
	engine = (Engine*)vmt.GetInterfaceVersion("engine.dll", "VEngineClient");
	JUNK(charter3);
	client = (Client*)vmt.GetInterfaceVersion("client.dll", "VClient");
	clientmode = **(ClientMode***)((*(DWORD**)client)[10] + 0x5);
	JUNK(charter4);
	netvars.Init();

	typedef void(__cdecl* MsgFn)(char const* fmt, ...);
	MsgFn Msg = (MsgFn)GetProcAddress(GetModuleHandleA("tier0.dll"), "Msg");

	Msg("%d\n", netvars.FindOffset("DT_BasePlayer", "m_fFlags"));

	oPaintTraverse = (PaintTraverseFn)vmt.HookVirtual(panel, 41, hkPaintTraverse);
	oCreateMove = (CreateMoveFn)vmt.HookVirtual(clientmode, 24, hkCreateMove);

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
