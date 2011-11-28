// Kevin Ferravanti Client Comm //
// TCP/IP //
#pragma once

#include<WinSock2.h> // For The Windows Socket API //
#include<vector>	// For The Message Queue	  //
#include<sstream>	// For Strings				  //

#define RCVBUFSIZE 64	// Message Buffer Size //

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
	std::string m_MessageToSend;		// Message To Send To Server		 //
	int m_MessageToSendLength;			// Length Of Message To Send		 //
	char m_MessageRecieved[RCVBUFSIZE];	// Buffer To Hold A Recieved Message //
	int m_MessageRecievedLength;		// Length Of Message Recieved		 //
	int m_MessageWasRecieved;			// Used For Checking				 //

	// Queue //
	std::vector<int> m_MessageQueue;	// Queue That Holds Messages The Client Recieved		 //
	std::vector<int>::iterator m_Iterator;
	int m_CurrentMessageNumber;			// Number Of The Message We Should Return From The Queue //

public:
	// Constructor //
	ClientComm(void);
	// Destructor //
	~ClientComm(void);
	// Returns An Int Based On Error Occured And A 1 If Successfull //
	int InitializeClient(std::string ServerIPAddress);
	// Returns True If There Is A Message Waiting //
	bool PeekMessage(void);
	// Returns The Next Message In The Queue //
	int GetNextMessage(void);
	// Returns An Int Based On Error Occured And A 1 If Successfull //
	int SendMessageToServer(int);
	// Returns An Int Based On Error Occured And A 1 If Successfull //
	int ListenForMessage(void);

	int ConnectToServer(void);

	void CloseClient(void);
	int MessageWasRecieved(void);
	char* GetMessage(void)
	{
		return m_MessageRecieved;
	}
};