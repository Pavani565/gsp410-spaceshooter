
#include <stdio.h>      /* for printf(), fprintf() */
#include <Winsock2.h>    /* for socket(),... */
#include <stdlib.h>     /* for exit() */

#define SENDBUFSIZE 512   /* Size of receive buffer */

#define MYMESG			"goodbye cruel world"
#define SRVR_ADDRESS	"127.0.0.1"
#define SRVR_PORT		8569



int main(int argc, char *argv[])
{
    SOCKET srvr_sock;                    /* Socket descriptor for server */
    struct sockaddr_in srvr_addr; /* Local address */
    WSADATA wsaData;                 /* Structure for WinSock setup communication */
	char sendbuf[SENDBUFSIZE];        /* Buffer for echo string */
	int send_len;                    /* Size of received message */
	int msgsize;
	int portnum = SRVR_PORT;

    if (argc ==  2) 
	{
		// argv[1] == the optional port number
		portnum = atoi(argv[1]);
	}

    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) /* Load Winsock 2.0 DLL */
    {
        fprintf(stderr, "WSAStartup() failed");
        return(-1);
    }

    // Create socket for incoming connections/
	//XXX - add call to socket() here with arguments to create a UDP client
    srvr_sock = socket(XXXXX);
	// if socket fails, it returns INVALID_SOCKET
	if (srvr_sock == INVALID_SOCKET)
	{
		fprintf(stderr, "Error: socket() failed with err number %d\n", WSAGetLastError());
		Sleep(5000);	// sleep added here so you can read the error number!
        return(-1);
	}

    // Construct local address structure
    memset(&srvr_addr, 0, sizeof(srvr_addr));   /* Zero out structure */
    srvr_addr.sin_family = AF_INET;                /* Internet address family */

    srvr_addr.sin_addr.s_addr = inet_addr(SRVR_ADDRESS);

    srvr_addr.sin_port = htons(portnum);      /* Server port */

	// Send message to 
	strcpy(sendbuf, MYMESG);

	//XXX implement call to sendto() here to send message to server
	send_len = sendto(XXXX,
				 XXXXX,
				 strlen(sendbuf) + 1,	// "+ 1" ensures that the null terminator is sent.
				 0,
				XXXX,
				XXXX);

	if (send_len == SOCKET_ERROR)
	{
		fprintf(stderr, "sendto() failed with err number %d\n", WSAGetLastError());
		Sleep(5000);	// sleep added here so you can read the error number!
		shutdown(srvr_sock, SD_BOTH);
		closesocket(srvr_sock);
        return(-1);
	}
	else
	{
		printf("Sent %d of %d bytes to %s:%u\n", send_len,
				strlen(sendbuf) + 1, inet_ntoa(srvr_addr.sin_addr), ntohs(srvr_addr.sin_port));
	}
	Sleep(5000);	// sleep added here so you can read the error number!
	shutdown(srvr_sock, SD_BOTH);
	closesocket(srvr_sock);
}
