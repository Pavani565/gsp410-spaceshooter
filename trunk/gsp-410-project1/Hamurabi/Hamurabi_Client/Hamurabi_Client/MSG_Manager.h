#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;


class MSG_Manager
{
private:
	MSG_Manager(void);
	static MSG_Manager * MSG;
	int gameNumber;
	string data;
public:
	~MSG_Manager(void);
	static MSG_Manager * getMSG();
	void putGameNumber(int);
	int getGameNumber();
	void putData(string);
	string getData();
	bool decode(string);
	string encode();

};

