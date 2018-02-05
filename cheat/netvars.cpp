
#include "netvars.h"
#include "client.h"
#include <cstring>
#include <Windows.h>

NetVars::NetVars(void)
{
	m_pClasses = 0;
}

ClientClass* NetVars::GetClasses(void)
{
	return m_pClasses;
}

void NetVars::SetClasses(ClientClass* classes)
{
	m_pClasses = classes;
}

RecvTable* NetVars::FindTable(char* tablename)
{
	ClientClass* clientClass;
	RecvTable* table;
	for (clientClass = m_pClasses; clientClass; clientClass = clientClass->m_pNext)
	{
		table = clientClass->m_pRecvTable;
		if (!strcmp(table->m_pNetTableName, tablename))
		{
			return table;
		}
	}

	return 0;
}

RecvProp* NetVars::FindProp(RecvTable* table, char* propname)
{
	typedef void(__cdecl* MsgFn)(char const* fmt, ...);
	MsgFn Msg = (MsgFn)GetProcAddress(GetModuleHandleA("tier0.dll"), "Msg");

	if (!table) return 0;
	RecvProp* prop = 0;
	for (int i = 0; i < table->m_nProps; i++)
	{
		prop = &table->m_pProps[i];
		if (!prop) { return 0; }
		if (!strcmp(prop->m_pVarName, propname))
		{
			return prop;
		}
	}

	return 0;
}

int NetVars::FindOffset(char* tablename, char* propname)
{
	RecvTable* table = FindTable(tablename);
	if (!table)
	{
		return 0;
	}
	
	RecvProp* prop = FindProp(table, propname);
	if (!prop)
	{
		return 0;
	}

	return prop->m_Offset;
}

NetVars netvars;
