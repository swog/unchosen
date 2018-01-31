
#include <Windows.h>
#include <memory.h>
#include <iostream>
#include "vmt.h"

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);

void* VMT::GetVirtual(void* instance, int index)
{
	return (void*)(*(DWORD*)(instance + sizeof(DWORD*) * index));
}

void* VMT::HookVirtual(void* instance, int index, void* replacement)
{
	DWORD oldFunc = GetVirtual(instance, index);
	return (void*)oldFunc;
}

void* VMT::GetInterface(char* module, char* name)
{
	CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(module), "CreateInterface");
	return CreateInterface(name);
}

inline void Format(char* buffer, size_t size, char* fmt, ...)
{
	memset(buffer, 0, size);
	va_list args;
  	va_start(args, format);
  	vsnprintf(buffer, size, format, args);
  	va_end(args);
}

void* VMT::GetInterfaceVersion(char* module, char* prefix)
{
}
	
VMT vmt;
