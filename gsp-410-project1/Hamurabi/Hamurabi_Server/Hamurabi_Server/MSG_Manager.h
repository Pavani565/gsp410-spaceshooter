#pragma once

#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;


class MSG_Manager
{
private:
	// Constructor //
	MSG_Manager(void);

	// Variables //
	static MSG_Manager * MSG;
	int gameNumber;
	string data;

public:
	// Destructor //
	~MSG_Manager(void);

	// Get Instance Pointer //
	static MSG_Manager * getMSG();

	// Set Game Number //
	void putGameNumber(int);
	// Get Game Number //
	int getGameNumber();

	// Set Data //
	void putData(string);
	// Get Data //
	string getData();

	// Comm Use Only //

	// Decode A String //
	bool decode(string);
	// Encode A String //
	string encode();

};

