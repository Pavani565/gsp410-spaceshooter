#include"ClientComm.h"

ClientComm::ClientComm(void)
{
	m_ClientSocket = 0;
	m_NetworkPort = 3001;
	m_MessageRecievedLength = 0;
	m_CurrentMessageNumber = 0;
	m_MessageToSend = "Hello Server!";
	m_MessageToSendLength = m_MessageToSend.length();
}
ClientComm::~ClientComm(void)
{
	m_ClientSocket = 0;
	m_NetworkPort = 0;
	m_MessageToSendLength = 0;
	m_MessageRecievedLength = 0;
	m_CurrentMessageNumber = 0;
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
bool ClientComm::PeekMessage(void)
{
	return false;
}
int ClientComm::GetNextMessage(void)
{
	return 0;
}
int ClientComm::SendMessageToServer(int)
{
	// Send Message To The Server //
	if (send(m_ClientSocket, m_MessageToSend.c_str(), m_MessageToSendLength, 0) != m_MessageToSendLength)
		return 2;
	else
		return 1;
}
int ClientComm::ListenForMessage(void)
{
	// A Message Has Not Been Recieved //
	m_MessageWasRecieved = 0;

	// Recieve Message From The Server //
	if ((m_MessageRecievedLength = recv(m_ClientSocket, m_MessageRecieved, RCVBUFSIZE - 1, 0)) <= 0)
	return 2;

	// A Message Was Recieved //
	m_MessageWasRecieved = 1;

	// Successs //
	return 1;
}

void ClientComm::CloseClient(void)
{
	closesocket(m_ClientSocket);
}

int ClientComm::MessageWasRecieved(void)
{
	return 0;
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