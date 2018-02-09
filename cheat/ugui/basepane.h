#ifndef BASEPANE_H
#define BASEPANE_H

#include <vector>

namespace ugui
{
        class BasePane
        {
        public:
                BasePane();
                
                virtual ~BasePane();
                
                virtual void Think() {}
                virtual void Paint() {}
                
                inline void PaintInternal() { if (!m_bPaint) return; Paint(); PaintElements(); }
                
                inline void SetPos(int x, int y) { m_posX = x; m_posY = y; }
                inline void GetPos(int& x, int& y) { x = m_posX; y = m_posY; }
                inline void SetSize(int w, int h) { m_sizeW = w; m_sizeH = h; }
                inline void GetSize(int& w, int& h) { w = m_sizeW; h = m_sizeH; }
                
                // Hierarchy
                inline BasePane* GetElement(int i) { return m_Elements.at(i); }
                inline std::vector<BasePane*> GetElements() { return m_Elements; }
                inline void CreateElement(BasePane* pane) { m_Elements.push_back(pane); }
                inline int  CountElements() { return m_Elements.capacity(); }
                void PaintElements();
                
                inline void SetParent(BasePane* parent) { parent->CreateElement(parent->GetPane()); m_pParent = parent; }
                inline BasePane* GetParent() { return m_pParent; }
                
                inline BasePane* GetPane() { return this; } // removes const
                
                inline void SetPaint(bool paint) { m_bPaint = paint; } // back over
                inline bool& GetPaint() { return m_bPaint; }
                
        private:
                int m_posX, m_posY;
                int m_sizeW, m_sizeH;
                std::vector<BasePane*> m_Elements;
                BasePane* m_pParent;
                bool m_bPaint;// ready for this
        };
        
        
        BasePane::BasePane()
        {
                m_posX = m_posY = 0;
                m_sizeW = m_sizeH = 100;
                m_Elements.clear();
                m_pParent = 0;
                m_bPaint = true;
        }
        
        BasePane::~BasePane()
        {
                for (BasePane* pane : m_Elements)
                {
                        delete pane;
                }
                
                m_Elements.clear(); // go to other file
        }
        
        inline void BasePane::PaintElements()
        {        
                for (BasePane* pane : m_Elements)
                {
                        pane->PaintInternal();
                }
        }
}

using namespace ugui;

#endif
