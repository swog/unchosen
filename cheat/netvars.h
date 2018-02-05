
#ifndef NETVARS_H
#define NETVARS_H

class ClientClass;
class RecvTable;
class RecvProp;

class NetVars
{
private:
	ClientClass* m_pClasses;

public:
	NetVars(void);

	ClientClass* GetClasses(void);
	void SetClasses(ClientClass* classes);

	RecvTable* FindTable(char* tablename);
	RecvProp* FindProp(RecvTable* table, char* propname);

	// Warning! Doesn't find recursively
	int FindOffset(char* tablename, char* propname);
};

extern NetVars netvars;

#endif