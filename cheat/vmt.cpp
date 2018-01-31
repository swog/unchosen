
#include <Windows.h>
#include "vmt.h"

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

void* VMT::GetVirtual(void* instance, int index)
{
}

void* VMT::HookVirtual(void* instance, int index, void* replacement)
{
}

void* VMT::GetInterface(char* module, char* name)
{
	CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(module), "CreateInterface");
	return CreateInterface(name);
}

void* VMT::GetInterfaceVersion(char* module, char* prefix)
{
}
	
VMT vmt;
