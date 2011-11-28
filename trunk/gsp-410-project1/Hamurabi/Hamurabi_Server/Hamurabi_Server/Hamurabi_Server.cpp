// Hamurabi_Server.cpp : Defines the entry point for the console application.
// Created 11-14-2011

#include "stdafx.h"
#include "Comm.h"
#include "MSG_Manager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ServerComm comm;

	/*
	// **BEGIN TEST** this is test code only.
	MSG_Manager::getMSG()->putGameNumber(4);
	MSG_Manager::getMSG()->putData("ACRES_SOLD;10");
	comm.checkMSG();
	if (comm.decodeTest("LEN 26:ID 3:DATA ACRES_BOUGHT;25:END"))
	cout << "The game number is " << MSG_Manager::getMSG()->getGameNumber() << " and the data is " << MSG_Manager::getMSG()->getData() << endl;
	else cout << "Decode Test failed!" << endl;	
	if (!comm.encodeTest()) cout << "Encode Test failed!" << endl;
	comm.checkMSG();
	// **END TEST** this is the end of the test code.
	*/

	printf("Init...\n");
	comm.InitalizeServer();
	printf("Listening...\n");
	comm.ListenForMessage();
	// do stuff //
	// send a message back //
	printf("Sending...\n");
	comm.SendMessageToClient();
	printf("Closing...\n");

	return 0;
}