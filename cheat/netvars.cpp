
#include "netvars.h"
#include "client.h"
#include "../junk.h"

void NetVars::Init(void)
{
	m_pClasses = client->GetAllClasses();
	JUNK(init);

	while (m_pClasses)
	{
		m_pTables.push_back(m_pClasses->m_pRecvTable);
		m_pClasses = m_pClasses->m_pNext;
	}
}

int NetVars::RecurseForOffset(RecvTable* pTable, char* childname)
{
	m_ExtraOffset = 0;

	for (int i = 0; i < pTable->m_nProps; i++)
	{
		RecvProp* pProp = &pTable->m_pProps[i];

		JUNK(bjord);

		RecvTable* pChildTable = pProp->m_pDataTable;

		if (pChildTable && pChildTable->m_nProps > 0)
		{
			int extra = RecurseForOffset(pChildTable, childname);

			if (extra)
			{
				return m_ExtraOffset += extra;
			}
		}

		if (!strcmp(pProp->m_pVarName, childname))
		{
			return pProp->m_Offset + m_ExtraOffset;
		}
	}
	return m_ExtraOffset;
}

RecvProp* NetVars::RecurseForProp(RecvTable* pTable, char* childname)
{
	for (int i = 0; i < pTable->m_nProps; i++)
	{
		RecvProp* pProp = &pTable->m_pProps[i];

		JUNK(iscool);

		RecvTable* pChildTable = pProp->m_pDataTable;

		if (pChildTable && pChildTable->m_nProps > 0)
		{
			RecvProp* pChild = RecurseForProp(pChildTable, childname);
			
			if (pChild)
			{
				return pChild;
			}
		}

		if (!strcmp(pProp->m_pVarName, childname))
		{
			return pProp;
		}
	}
	return nullptr;
}

int NetVars::FindOffset(char* tablename, char* childname)
{
	if (m_pTables.empty())
	{
		return 0;
	}

	for (RecvTable* pTable : m_pTables)
	{
		if (!strcmp(pTable->m_pNetTableName, tablename))
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
		if (!strcmp(pTable->m_pNetTableName, tablename))
		{
			return RecurseForProp(pTable, childname);
		}
	}
}

NetVars netvars;
