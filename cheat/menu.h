
#include "vector.h"
#include "settings.h"

class Menu
{
private:
	Vector m_Pos;
	Vector m_Size;
	char* m_Title;
	const Vector m_CheckBoxSize = Vecotr(0, 0, 0);
	
	void GetCursorPos(int& cx, int& cy);
	void DrawCheckbox(char* label, int x, int y, int w, int h, bool& setting);
	
public:
	Menu(void);
	void PaintTraverse(void);
};

extern Menu menu;
