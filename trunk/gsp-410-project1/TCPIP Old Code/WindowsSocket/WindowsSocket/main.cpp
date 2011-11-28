//Kevin Ferravanti//
//TCP/IP Windows Socket Code//

#include<iostream>
#include<stdio.h>
#include<WinSock2.h>
#include<stdlib.h>
using namespace std;

#include "ClientComm.h"

#define RCVBUFSIZE 64

void DieWithError(char *errorMessage);

void main(int argc, char *argv[])
{
	int ErrorNumber = 1;
	string ServIP = "127.0.0.1";
	ClientComm CommCenter;
	printf("Enter Server IP Address: 127.0.0.1\n");

	printf("Initializing Client\n");
	CommCenter.InitializeClient(ServIP);

	while(true)
	{
		printf("Connecting to Server\n");
		CommCenter.ConnectToServer();

		printf("Sending Message\n");
		ErrorNumber = CommCenter.SendMessageToServer(1);

		if(ErrorNumber != 1)
			printf("Could Not Send Message (Error %i, %i)\n", ErrorNumber, WSAGetLastError());
		else
		{
			printf("Message Sent\n");
			printf("Recieving Message\n");
			ErrorNumber = CommCenter.ListenForMessage();
			if(ErrorNumber != 1)
			{
				printf("Failed Listening For Message (Error %i, %i)\n", ErrorNumber, WSAGetLastError());
			}
			else
			{
				printf("Message: %s\n", CommCenter.GetMessage());
			}
		}
		CommCenter.CloseClient();
	}
}