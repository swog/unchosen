
#include "vector.h"
#include "settings.h"

class Menu
{
private:
	Vector m_Pos;
	Vector m_Size;
	char* m_Title;
	
	void GetCursorPos(int& cx, int& cy);
	
public:
	Menu(void);
	void PaintTraverse(void);
};

extern Menu menu;
