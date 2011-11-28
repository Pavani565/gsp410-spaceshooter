// Kevin Ferravanti Client Comm //
// TCP/IP //
#pragma once

#include<WinSock2.h> // For The Windows Socket API //
#include<vector>	 // For The Message Queue	   //
#include<sstream>	 // For Strings				   //

#include "MSG_Manager.h"

#define RCVBUFSIZE 256	// Message Buffer Size //

class ClientComm
{
private:
	// Socket //
	SOCKET m_ClientSocket;				// Socket Descriptor For Client    //
	struct sockaddr_in m_ServerAddress;	// Client Address Structure		   //
	int m_NetworkPort;					// Server Port Number			   //
	std::string m_ServerIPAddress;		// Server IP Address			   //
	WSADATA m_WSAData;					// Windows Socket Application Data //

	// Message //	
	char m_MessageRecieved[RCVBUFSIZE];	// Buffer To Hold A Recieved Message //
	int m_MessageRecievedLength;		// Length Of Message Recieved		 //

public:
	// Constructor //
	ClientComm(void);
	// Destructor //
	~ClientComm(void);
	// Returns An Int Based On Error Occured And A 1 If Successfull //
	int InitializeClient(std::string ServerIPAddress);
	// Returns True If There Is A Message Waiting //
	int SendMessageToServer(void);
	// Returns An Int Based On Error Occured And A 1 If Successfull //
	int ListenForMessage(void);
	// Returns An Int Based On Error Occured And A 1 If Successfull //
	int ConnectToServer(void);
	// This Function Closes The Socket When Communication Is Finished Per Message //
	void CloseSocket(void);

	// Place Holder Function //
	void checkMSG(void);
	// More Test Functions //
	bool encodeTest();
	bool decodeTest(string);

};
