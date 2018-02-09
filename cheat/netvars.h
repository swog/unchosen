
#ifndef NETVARS_H
#define NETVARS_H

#include <vector>

class ClientClass;
class RecvTable;
class RecvProp;

class NetVars
{
	ClientClass* m_pClasses;
	std::vector<RecvTable*> m_pTables;
	int m_ExtraOffset;
	
	int RecurseForOffset(RecvTable* pTable, char* childname);
	RecvProp* RecurseForProp(RecvTable* pTable, char* childname);
public:
	
	void Init(void);
	
	int FindOffset(char* tablename, char* childname);
	RecvProp* FindProp(char* tablename, char* childname);
};

extern NetVars netvars;

#endif
