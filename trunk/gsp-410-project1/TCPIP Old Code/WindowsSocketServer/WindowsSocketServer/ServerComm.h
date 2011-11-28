// Kevin Ferravanti Server Comm //
// TCP/IP //
#pragma once

#include<WinSock2.h>// For The Windows Socket API //
#include<vector>	// For The Message Queue //
#include<sstream>	// For Strings //

#define RCVBUFSIZE 64	// Message Buffer Size //
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
	WSAEVENT m_WSAEvent;				// Windows Event Handle //

	// Message //
	char m_MessageRecieved[RCVBUFSIZE];	// Buffer To Hold Recieved Message //
	int m_MessageRecievedLength;		// Size of received message //
	char* m_MessageToSend;				// Message to send back //
	int m_MessageToSendLength;			// Size Of Message To Send Back //
	int m_MessageWasRecieved;			// Used For Checking //

	// Queue //
	std::vector<int> m_MessageQueue;	// Queue That Holds Messages The Server Recieved //
	std::vector<int>::iterator m_Iterator;
	int m_CurrentMessageNumber;			// Number Of The Message We Should Return From The Queue //

public:
	// Constructor //
	ServerComm(void);
	// Destructor //
	~ServerComm(void);
	// Returns An Int Based On What Type Of Error Occured And A 1 If Successful//
	int InitalizeServer(void);
	// Return True If There Is A Message Waiting In The Queue //
	bool PeekMessage(void);
	// Return The Next Message In The Queue //
	int  GetNextMessage(void);
	// Returns An Int Based On What Type Of Error Occured And A 0 If Successful And 1 If A Message Was Recieved//
	int AcceptClients(void);
	// Returns A Zero If Send Failed And A 1 If Send Was Successful
	int SendMessageToClient(int Message);

	void CloseClient(void);
	int MessageWasRecieved(void);

	char* GetMessage(void)
	{
		return m_MessageRecieved;
	}
};