
#ifndef OFFSETS_H
#define OFFSETS_H

class Offsets
{
public:
	Offsets();
	void Init();
	
	int m_fFlags;
	int m_vecViewOffset;
	int m_iTeamNum;
};

extern Offsets offsets;

#endif
