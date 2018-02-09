#ifndef LABEL_H
#define LABEL_H

#include "basepane.h"

namespace ugui
{
        enum LabelFormat_t
        {
                TEXT_FORMAT_LEFT,
                TEXT_FORMAT_CENTER,
                TEXT_FORMAT_RIGHT,
                TEXT_FORMAT_TOP,
                TEXT_FORMAT_VCENTER,
                TEXT_FORMAT_BOTTOM,
        }
        
        class Label : public BasePane
        {
        public:
                Label();
                Label(char* text);
                Label(char* text, BasePane* parent);
                
                virtual ~Label();
                
                virtual void Think();
                virtual void Paint();
                
        public:
                void SetText(char* text);
                char* GetText();
                void SetFormat(int format);
                int GetFormat();
                
        private:
                /* ~==~ [Magic] ~==~ */
                void FormatTextPos(int& x, int& y);
        
                char* m_Text;
                int m_fFormat; // its a combination of flags

                
        };
}

#endif
