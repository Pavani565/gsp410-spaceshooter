// Hamurabi_Client.cpp : Defines the entry point for the console application.
// Created 11-7-2011 by David Walker
// Base Code: 11-7-2011

#include "stdafx.h"
#include "Comm.h"
#include "MSG_Manager.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ClientComm comm;

	/*
	//To Do [Client by William Zepeda]
	// **BEGIN TEST** this is test code only.  Delete when UI is written.
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
	comm.InitializeClient("127.0.0.1");
	// Do Stuff //
	printf("Sending...\n");
	comm.SendMessageToServer();
	// Wait For a Reply //
	printf("Listening...\n");
	comm.ListenForMessage();
	printf("Closing...\n");
	comm.CloseSocket();
	return 0;
}