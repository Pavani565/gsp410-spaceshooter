#pragma once
#include<string>
class CustomMessage
{
private:
	int		m_Value1,	m_Value2,	m_Value3;
	char*	m_Text1;
	char	m_Buffer[31];
public:
	CustomMessage()
	{
		m_Value1	= 1;
		m_Value2	= 2;
		m_Value3	= 3;
		m_Text1		= "ThisIsAChar*";
	}
	int		getValue1	(void);
	int		getValue2	(void);
	int		getValue3	(void);
	char*	getText1	(void);
	void	setText		(char* newText);

	char* GetPackageMessage(void);
};