
#include <Windows.h>
#include <memory.h>
#include <iostream>
#include "vmt.h"
#include "../junk.h"

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

void* VMT::GetVirtual(void* instance, int index)
{
	DWORD VirtualFunction = (*(DWORD*)instance) + sizeof(DWORD) * index;
	JUNK(virtual1);
	return (void*)(*((DWORD*)VirtualFunction));
}

void* VMT::HookVirtual(void* instance, int index, void* replacement)
{
	DWORD VirtualTable = *(DWORD*)instance;
	DWORD VirtualFunction = VirtualTable + sizeof(DWORD) * index;
	DWORD OriginalFunction = *(DWORD*)VirtualFunction;
	DWORD OldProtect;
	JUNK(virtual1);
	VirtualProtect((void*)VirtualFunction, sizeof(DWORD), PAGE_EXECUTE_READWRITE, &OldProtect);
	*(DWORD*)VirtualFunction = (DWORD)replacement;
	JUNK(virtual2);
	VirtualProtect((void*)VirtualFunction, sizeof(DWORD), OldProtect, &OldProtect);
	return (void*)OriginalFunction;
}

void* VMT::GetInterface(char* module, char* name)
{
	JUNK(virtual4);
	CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(module), "CreateInterface");
	return CreateInterface(name, 0);
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
