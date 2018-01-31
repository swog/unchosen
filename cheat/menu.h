
#include "vector.h"

class Menu
{
private:
	Vector m_Pos;
	Vector m_Size;
	char* m_Title;
	
	void GetCursorPos(int& cx, int& cy);
	
public:
	void PaintTraverse(void);
};

extern Menu menu;
