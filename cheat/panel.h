
#ifndef PANEL_H
#define PANEL_H

typedef unsigned int VPANEL;

class Panel
{
public:
	const char* GetClassname(VPANEL vguiPanel);
};

extern Panel* panel;

#endif
