#include"Comm.h"

ServerComm::ServerComm(void)
{
	m_ServerSocket = 0;
	m_ClientSocket = 0;
	m_NetworkPort = 3001; // This Port Is Usually Not Used By Anything //
	m_ClientAddressLength = 0;
	m_MessageRecievedLength = 0;
}

ServerComm::~ServerComm(void)
{
	m_ServerSocket = 0;
	m_ClientSocket = 0;
	m_NetworkPort = 0;
	m_ClientAddressLength = 0;
	m_MessageRecievedLength = 0;
	if(m_ServerSocket != 0)
		closesocket(m_ServerSocket);
	if(m_ClientSocket != 0)
		closesocket(m_ClientSocket);
	WSACleanup();
}

int ServerComm::InitalizeServer(void)
{
	// Load Winsock 2.2 DLL //
	if(WSAStartup(MAKEWORD(2, 2), &m_WSAData) != 0)
		return 2;

	// Check The Winsock Version //
	if (LOBYTE(m_WSAData.wVersion) != 2 || HIBYTE(m_WSAData.wVersion) != 2 )
	{
		// Clean Up The WSAData //
		WSACleanup();
		return 3;
	}

	// Create the Server's Socket //
	if((m_ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		WSACleanup();
		return 4;
	}
	
	// This Code Is For Making The Server Non Blocking //
	/*
	u_long mode = 0;
	ioctlsocket(m_ServerSocket, FIONBIO, &mode);
	*/

	// Zero Out The Server Address Structure //
	std::memset(&m_ServerAddress, 0, sizeof(m_ServerAddress));

	// Set The Server Address Family Type IPv4 //
	m_ServerAddress.sin_family = AF_INET;
	// Set The Server To Listen On All Interfaces (host to network byte order) //
	m_ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	// Set The Port Number This TCP/IP Uses (host to network byte order) //
	m_ServerAddress.sin_port = htons(m_NetworkPort);

	// "Bind" the Server Socket And The Server Address Information //
	if(bind(m_ServerSocket, (sockaddr*) &m_ServerAddress, sizeof(m_ServerAddress)) == SOCKET_ERROR)
	{
		closesocket(m_ServerSocket);
		WSACleanup();
		return 5;
	}

	//Set The Server To Listen For Incoming Transmissions //
	if(listen(m_ServerSocket, MAXPENDING) == SOCKET_ERROR)
	{
		closesocket(m_ServerSocket);
		WSACleanup();
		return 6;
	}

	// Success //
	return 1;
}

int ServerComm::ListenForMessage(void)
{
	// Set The Size If The In-Out Parameter //
	m_ClientAddressLength = sizeof(m_ClientAddress);

	// Try To Connect With Client //
	if((m_ClientSocket = accept(m_ServerSocket, (struct sockaddr *) &m_ClientAddress, &m_ClientAddressLength)) < 0)
			return 2;

	printf("Handling client %s\n", inet_ntoa(m_ClientAddress.sin_addr));

	// Receive Message From Client //
	if ((m_MessageRecievedLength = recv(m_ClientSocket, m_MessageRecieved, RCVBUFSIZE, 0)) < 0)
		return 3;


	// May Not Be Needed //
	size_t strIndex;
	std::stringstream sstream;
	sstream << m_MessageRecieved;
	m_ConvertedMessage = sstream.str();
	strIndex = m_ConvertedMessage.find(":END") + 4;
	if(strIndex < m_ConvertedMessage.length())
	{
		std::string::iterator tempIter= m_ConvertedMessage.begin()+strIndex;
		m_ConvertedMessage.erase(tempIter, m_ConvertedMessage.end());
	}
	MSG_Manager::getMSG()->decode(m_ConvertedMessage);
	//  //

	return 1;
}

int ServerComm::SendMessageToClient(void)
{
	if (send(m_ClientSocket, MSG_Manager::getMSG()->encode().c_str(), strlen(MSG_Manager::getMSG()->encode().c_str()), 0) != strlen(MSG_Manager::getMSG()->encode().c_str()))
		return 0;
	else
		return 1;
}

void ServerComm::CloseClient(void)
{
	closesocket(m_ClientSocket);
}

void ServerComm::checkMSG(void)
{
	printf("Game Number is: %i", MSG_Manager::getMSG()->getGameNumber());
}

bool ServerComm::decodeTest(string theMsg)
{
	return MSG_Manager::getMSG()->decode(theMsg);
}

bool ServerComm::encodeTest(void)
{
	string theMsg;
	 theMsg = MSG_Manager::getMSG()->encode();
	 cout << theMsg << endl;
	 if (theMsg.compare("ERROR") == 0) return false;
	 return true;
}