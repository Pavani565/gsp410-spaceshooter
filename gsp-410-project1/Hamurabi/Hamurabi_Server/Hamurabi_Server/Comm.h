// Kevin Ferravanti Server Comm //
// TCP/IP //
#pragma once

#include<WinSock2.h>// For The Windows Socket API //
#include<sstream>	// For Strings //

#include "MSG_Manager.h"

#define RCVBUFSIZE 256	// Message Buffer Size //
#define MAXPENDING 5	// Maximum Outstanding Connection Requests //
						// 5 Is Common //
class ServerComm
{
private:
	// Socket //
	SOCKET m_ServerSocket;				// Socket Descriptor For Server //
	SOCKET m_ClientSocket;				// Socket Descriptor For Client //
	struct sockaddr_in m_ServerAddress;	// Server Address Structure //
	struct sockaddr_in m_ClientAddress;	// Client Address Structure //

	unsigned int m_NetworkPort;			// Server Port Number //
	int m_ClientAddressLength;			// Length Of Client Address Data Structure //
	WSADATA m_WSAData;					// Windows Socket Application Data //

	// Message //
	char m_MessageRecieved[RCVBUFSIZE];	// Buffer To Hold Recieved Message //
	int m_MessageRecievedLength;		// Size of received message //
	std::string m_ConvertedMessage;		// String To Hold Recieved Message To Be Decoded //

public:
	// Constructor //
	ServerComm(void);
	// Destructor //
	~ServerComm(void);
	// Returns An Int Based On What Type Of Error Occured And A 1 If Successful//
	int InitalizeServer(void);
	// Returns An Int Based On What Type Of Error Occured And A 0 If Successful And 1 If A Message Was Recieved//
	int ListenForMessage(void);
	// Returns A Zero If Send Failed And A 1 If Send Was Successful
	int SendMessageToClient(void);

	void CloseClient(void);

	// Place Holder Function //
	void checkMSG(void);
	bool encodeTest(void);
	bool decodeTest(string theMsg);
};