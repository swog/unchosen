
#include "vector.h"
#include "color.h"
#include "settings.h"

class Menu
{
private:
	Vector m_Pos;
	Vector m_Size;
	char* m_Title;
	
	union
	{
		const Vector m_CheckBoxSize(0, 0, 0);
		const Color m_CheckBoxColor(255, 255, 255, 255);
	};
	
	void GetCursorPos(int& cx, int& cy);
	void DrawCheckbox(char* label, int x, int y, int w, int h, bool& setting);
	
public:
	Menu(void);
	void PaintTraverse(void);
};

extern Menu menu;
