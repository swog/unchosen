
#ifndef BASEPANE_H
#define BASEPANE_H

namespace ugui
{
	class BasePane
	{
	public:
		virtual void Think() {}
		virtual void Paint() {}
		
		inline void SetPos(int x, int y) { m_posX = x; m_posY = y; }
		inline void GetPos(int& x, int& y) { x = m_posX; y = m_posY; }
		inline void SetSize(int w, int h) { m_sizeW = w; m_sizeH = h; }
		inline void GetSize(int& w, int& h) { w = m_sizeW; h = m_sizeH; }
		
	private:
		int m_posX, m_posY;
		int m_sizeW, m_sizeH;
	};
}

#endif
