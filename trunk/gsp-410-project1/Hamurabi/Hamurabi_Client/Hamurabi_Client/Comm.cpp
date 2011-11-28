#include "Comm.h"

ClientComm::ClientComm(void)
{
	m_ClientSocket = 0;
	m_NetworkPort = 3001;
	m_MessageRecievedLength = 0;
}
ClientComm::~ClientComm(void)
{
	m_ClientSocket = 0;
	m_NetworkPort = 0;
	m_MessageRecievedLength = 0;
	closesocket(m_ClientSocket);
	WSACleanup();

}
int ClientComm::InitializeClient(std::string ServerIPAddress)
{
	// Set The Server IP Address To What The User Input //
	m_ServerIPAddress = ServerIPAddress;

	// Load Winsock 2.2 DLL //
	if(WSAStartup(MAKEWORD(2, 2), &m_WSAData) != 0)
		return 2;

	// Zero Out The Client Address Structure //
	memset(&m_ServerAddress, 0, sizeof(m_ServerAddress));

	// Set The Server Address Family Structure //
	m_ServerAddress.sin_family = AF_INET;
	// Set The IP Address Of The Server //
	m_ServerAddress.sin_addr.s_addr = inet_addr(m_ServerIPAddress.c_str());
	// Set The Port Number This TCP/IP Uses //
	m_ServerAddress.sin_port = htons(m_NetworkPort);

	// Success //
	return 1;
}

int ClientComm::SendMessageToServer(void)
{
	if(ConnectToServer()==1)
	{
		// Send Message To The Server //
		if (send(m_ClientSocket, MSG_Manager::getMSG()->encode().c_str(), strlen(MSG_Manager::getMSG()->encode().c_str()), 0) != strlen(MSG_Manager::getMSG()->encode().c_str()))
			return 2;
		else
		{
			//shutdown(m_ClientSocket, SD_SEND);
			return 1;
		}
	}
	else 
		return 3;
}
int ClientComm::ListenForMessage(void)
{
	// Recieve Message From The Server //
	if ((m_MessageRecievedLength = recv(m_ClientSocket, m_MessageRecieved, RCVBUFSIZE - 1, 0)) <= 0)
		return 2;

	// Successs //
	return 1;
}

void ClientComm::CloseSocket(void)
{
	closesocket(m_ClientSocket);
}

int ClientComm::ConnectToServer(void)
{

	// Create The Client's Socket //
	if ((m_ClientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
		return 2;

	//Connect To The Server //
	if(connect(m_ClientSocket, (struct sockaddr *) &m_ServerAddress, sizeof(m_ServerAddress)) < 0)
		return 3;

	// Success //
	return 1;
}


void ClientComm::checkMSG(void)
{
	printf("Game Number is: %i\n", MSG_Manager::getMSG()->getGameNumber());
	printf("Data is: %s\n", MSG_Manager::getMSG()->getData());
}

bool ClientComm::decodeTest(string theMsg)
{
	return MSG_Manager::getMSG()->decode(theMsg);
}

bool ClientComm::encodeTest(void)
{
	string theMsg;
	 theMsg = MSG_Manager::getMSG()->encode();
	 cout << theMsg << endl;
	 if (theMsg.compare("ERROR") == 0) return false;
	 return true;
}