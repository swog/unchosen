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
	};
        
	class Label : public BasePane
	{
	public:

		Label();
		Label(char* text);
		Label(char* text, BasePane* parent);
                
		virtual ~Label() {}
                
		virtual void Think() {}
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
		int m_fFormat; // its a combination of flags  '

	};
}

inline Label::Label()
{
	m_Text = const_cast<char*>("Default");
}

inline Label::Label(char* text)
{
	m_Text = text;
}

inline Label::Label(char* text, BasePane* parent)
{
	m_Text = text;
	//this->SetParent(parent);
}

inline void Label::SetText(char* text)
{
	m_Text = text;
}

inline char* Label::GetText()
{
	return m_Text;
}

inline void Label::SetFormat(int format)
{

}

inline int Label::GetFormat()
{
	return m_fFormat;
}

inline void Label::FormatTextPos(int & x, int & y)
{

}

#endif

