
#include <Windows.h>
#include <TlHelp32.h>
#include <cstring>
#include "../junk.h"

DWORD GetProcID(char* exename)
{
	JUNK(procid);
	
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	
	PROCESSENTRY32 pe32;
	memset(&pe32, 0, sizeof(pe32));
	pe32.dwSize = sizeof(PROCESSENTRY32);
	
	JUNK(procid2);
	
	DWORD procID = 0;
	BOOL cont;
	for (cont = Process32First(snapshot, &pe32); cont; cont = Process32Next(snapshot, &pe32))
	{
		if (!strcmp(pe32.szExeFile, exename))
		{
			procID = pe32.th32ProcessID;
			break;
		}
	}
	
	JUNK(procid3);
	
	CloseHandle(snapshot);
	
	return procID;
}

int main(int argc, char** argv)
{
	JUNK(main);
	
	DWORD procID = GetProcID("csgo.exe");
	
	if (!procID)
	{
		return 0;
	}
	
	JUNK(main2);
	
	char dlldir[MAX_PATH];
	GetFullPathName("cheat/unchosen.dll", MAX_PATH, dlldir, 0);
	
	JUNK(main3);
	
	HANDLE process = OpenProcess(PROCESS_ACCESS_ALL, false, procID);
	
	LPVOID loadLibrary = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll", "LoadLibraryA"));
	LPVOID memory = VirtualAllocEx(process, 0, strlen(dlldir) + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	JUNK(main4);
	
	WriteProcessMemory(process, memory, dlldir, strlen(dlldir) + 1, 0);
	CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)loadLibrary, memory, 0, 0);
	
	CloseHandle(process);
	
	return 0;
}
