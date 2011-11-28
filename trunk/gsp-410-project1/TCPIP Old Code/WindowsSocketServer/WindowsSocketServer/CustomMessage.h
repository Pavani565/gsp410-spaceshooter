#pragma once

class CustomMessage
{
private:
	int		m_Value1,	m_Value2,	m_Value3;
	char*	m_Text1;
public:
	CustomMessage()
	{
		m_Value1	= 1;
		m_Value2	= 2;
		m_Value3	= 3;
		m_Text1		= "Text1";
	}
	int getValue1(void)
	{
		return m_Value1;
	}
	int getValue2(void)
	{
		return m_Value2;
	}
	int getValue3(void)
	{
		return m_Value3;
	}
	char* getText1(void)
	{
		return m_Text1;
	}
	void setText(char* newText)
	{
		m_Text1 = newText;
	}
};