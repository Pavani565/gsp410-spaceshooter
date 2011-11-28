#include"CustomMessage.h"
#include<sstream>

int CustomMessage::getValue1(void)
{
	return m_Value1;
}
int CustomMessage::getValue2(void)
{
	return m_Value2;
}
int CustomMessage::getValue3(void)
{
	return m_Value3;
}
char* CustomMessage::getText1(void)
{
	return m_Text1;
}
void CustomMessage::setText(char* newText)
{
	m_Text1 = newText;
}
char* CustomMessage::GetPackageMessage(void)
{
	std::stringstream StringPackager;
	StringPackager << m_Value1 << m_Value2 << m_Value3 << m_Text1;

	std::string MyString = StringPackager.str();

	int StringLength = MyString.length();

	if(StringLength>32)
	{
		printf("Too Much Data");
	}

	for (int index = 0; index  < StringLength; index++)
	{
		m_Buffer[index] = MyString[index];
	}

	return m_Buffer;
}