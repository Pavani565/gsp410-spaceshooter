//Kevin Ferravanti//
//TCP/IP Windows Socket Code//

#include <stdio.h>	// for printf() and fprintf() //
#include <stdlib.h>	// for atoi() and exit() //
#include <string.h>	// for memset() //

#include<WinSock2.h>// for the windows socket api //

#include"ServerComm.h"

int main(int argc, char *argv[])
{
	int ErrorNumber = 1;
	ServerComm CommCenter;
	printf("Initializing Server\n");
	if(CommCenter.InitalizeServer() == 1)
	{
		printf("Listening\n");
		while(true)
		{
			ErrorNumber = CommCenter.AcceptClients();

			if(ErrorNumber != 1)
				printf("Error Listening For Message (Error %i, %i)\n", ErrorNumber, WSAGetLastError());
			else
			{
				printf("Successfully Listened\n");
				printf("Message: %s\n", CommCenter.GetMessage());
				printf("Sending Message Back\n");
				ErrorNumber = CommCenter.SendMessageToClient(1);
				if(ErrorNumber != 1)
					printf("Error Sending Message (Error %i, %i)\n", ErrorNumber, WSAGetLastError());
				else
					printf("Message Sent\n");
			}
		}
	}
	else 
		return 0;
}
