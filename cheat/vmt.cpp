
#include <Windows.h>
#include <memory.h>
#include <iostream>
#include "vmt.h"
#include "../junk.h"

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

void* VMT::GetVirtual(void* instance, int index)
{
	JUNK(virtual);	
	return (void*)(*(DWORD*)(instance + sizeof(DWORD*) * index));
}

void* VMT::HookVirtual(void* instance, int index, void* replacement)
{
	JUNK(virtual);
	DWORD* vfunc = (DWORD*)(instance + sizeof(DWORD*) * index);
	DWORD oldFunc = *vfunc;
	DWORD oldProt;
	JUNK(virtual2);
	VirtualProtect((void*)*vfunc, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProt);
	*vfunc = (DWORD)replacement;
	VirtualProtect((void*)*vfunc, sizeof(DWORD), oldProt, 0);
	JUNK(virtual3);
	return (void*)oldFunc;
}

void* VMT::GetInterface(char* module, char* name)
{
	JUNK(virtual4);
	CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(module), "CreateInterface");
	return CreateInterface(name);
}

inline void Format(char* buffer, size_t size, char* fmt, ...)
{
	JUNK(format);
	memset(buffer, 0, size);
	va_list args;
  	va_start(args, fmt);
	JUNK(format2);
  	vsnprintf(buffer, size, fmt, args);
  	va_end(args);
}

void* VMT::GetInterfaceVersion(char* module, char* prefix)
{
	JUNK(version);
	char buffer[255];
	void* found = 0;
	
	for (int i = 0; i < 100; i++)
	{
		if (found)
		{
			return found;
		}
		
		JUNK(version2);
		
		Format(buffer, sizeof(buffer), "%s0%d", prefix, i);
		found = GetInterface(module, buffer);
		
		if (found)
		{
			return found;
		}
		
		JUNK(version3);
		
		Format(buffer, sizeof(buffer), "%s00%d", prefix, i);
		found = GetInterface(module, buffer);
		
		if (found)
		{
			return found;
		}
	}
	
	JUNK(version4);
	
	return 0;
}
	
VMT vmt;
