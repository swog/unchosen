
#include "netvars.h"
#include "client.h"

NetVars::NetVars(void)
{
	m_pClasses = 0;
}

void NetVars::Init(void)
{
	m_pClasses = client->GetAllClasses();

	while (m_pClasses)
	{
		m_pTables.push_back(m_pClasses->m_pRecvTable);
		m_pClasses = m_pClasses->m_pNext;
	}
}

int NetVars::RecurseForOffset(RecvTable* pTable, char* childname)
{
	for (int i = 0; i < pTable->m_nProps; i++)
	{
		RecvProp* pProp = &pTable->m_pProps[i];
		
		RecvTable* pChildTable = pProp->m_pDataTable;

		if (!pChildTable || pChildTable->m_nProps <= 0)
		{
			if (strcmp(pProp->m_pVarName, childname) != 0)
			{
				return pProp->m_Offset;
			}
		}

		return pProp->m_Offset + RecurseForOffset(pChildTable, childname);
	}
}

RecvProp* NetVars::RecurseForProp(RecvTable* pTable, char* childname)
{
	for (int i = 0; i < pTable->m_nProps; i++)
	{
		RecvProp* pProp = &pTable->m_pProps[i];

		RecvTable* pChildTable = pProp->m_pDataTable;

		if (!pChildTable || pChildTable->m_nProps <= 0)
		{
			if (strcmp(pProp->m_pVarName, childname) != 0)
			{
				return pProp;
			}
		}

		return RecurseForProp(pChildTable, childname);
	}
}

int NetVars::FindOffset(char* tablename, char* childname)
{
	if (m_pTables.empty())
	{
		return 0;
	}

	for (RecvTable* pTable : m_pTables)
	{
		if (strcmp(pTable->m_pNetTableName, tablename) != 0)
		{
			return RecurseForOffset(pTable, childname);
		}
	}
}

RecvProp* NetVars::FindProp(char* tablename, char* childname)
{
	if (m_pTables.empty())
	{
		return nullptr;
	}

	for (RecvTable* pTable : m_pTables)
	{
		if (strcmp(pTable->m_pNetTableName, tablename) != 0)
		{
			return RecurseForProp(pTable, childname);
		}
	}
}

NetVars netvars;
