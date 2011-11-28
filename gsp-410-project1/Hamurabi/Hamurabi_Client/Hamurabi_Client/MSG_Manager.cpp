#include "MSG_Manager.h"

MSG_Manager * MSG_Manager::MSG = NULL;

MSG_Manager::MSG_Manager(void)
{
}


MSG_Manager::~MSG_Manager(void)
{
}

MSG_Manager * MSG_Manager::getMSG()
{
	if (MSG == NULL)
		MSG = new MSG_Manager();
	return MSG;

}

void MSG_Manager::putGameNumber(int num)
{
	gameNumber = num;
	return;
}
int MSG_Manager::getGameNumber()
{
	return gameNumber;
}
void MSG_Manager::putData(string newData)
{
	data = newData;
}
string MSG_Manager::getData()
{
	return data;
}

// Parses a message string to extract the Game Number and Data
bool MSG_Manager::decode(string msgStr)
{
	size_t strIndex1, strIndex2;
	stringstream tempStr;
	strIndex1 = msgStr.find("LEN");
	if (strIndex1 != 0) return false;
	strIndex1 = msgStr.find(":ID") + 4;
	strIndex2 = msgStr.find(":DATA") - strIndex1;
	tempStr << msgStr.substr(strIndex1, strIndex2);
	if (!(tempStr >> gameNumber)) return false;
	strIndex1 = msgStr.find(":DATA") + 6;
	strIndex2 = msgStr.find(":END") - strIndex1;
	data = msgStr.substr(strIndex1, strIndex2);
	//tempStr.clear();
	//tempStr << msgStr.substr(strIndex1, strIndex2);
	//if (!(tempStr >> data)) return false;
	return true;
}

// Creates the text string to send out via TCP/IP
string MSG_Manager::encode()
{
	string msgString;
	stringstream tempStr, tempStr1;
	int digit_count;
	tempStr << "LEN 000:ID " << gameNumber << ":DATA " << data << ":END";
	tempStr1 << tempStr.str().size();
	digit_count = tempStr1.str().size();	
	msgString=tempStr.str();
	msgString.replace(7 - digit_count, digit_count,  tempStr1.str());	
	return msgString;
}