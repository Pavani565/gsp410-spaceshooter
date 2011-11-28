
#include <stdio.h>      /* for printf(), fprintf() */
#include <Winsock2.h>    /* for socket(),... */
#include <stdlib.h>     /* for exit() */

#define RCVBUFSIZE 512  /* Size of receive buffer */
#define SRVR_ADDRESS	"127.0.0.1"
#define SRVR_PORT		8569

int main(int argc, char *argv[])
{
    SOCKET srvr_sock;                    /* Socket descriptor for server */
    struct sockaddr_in srvr_addr; /* Local address */
    struct sockaddr_in clnt_addr; /* Client address */
    int clntLen =0;            /* Length of client address data structure */
	int err;
    WSADATA wsaData;                 /* Structure for WinSock setup communication */
	char recv_buf[RCVBUFSIZE];        /* Buffer for echo string */
	int bytes_rcvd;                    /* Size of received message */

   
    if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0) /* Load Winsock 2.0 DLL */
    {
        fprintf(stderr, "WSAStartup() failed\n");
		return(-1);
    }

 //XXX - Create socket for incoming connections
    if ((srvr_sock = socket(XXX)) == INVALID_SOCKET)
	{
        fprintf(stderr, "socket() failed due to error %d\n",
				GetLastError());
		return(-1);
	}

    // Construct local address structure
    memset(&srvr_addr, 0, sizeof(srvr_addr));		/* Zero out structure */
    srvr_addr.sin_family = AF_INET;					 /* Internet address family */

    // NOTE: inet_addr() CAN fail, so you should test the result and modify the following
	// line of code appropriately.
	srvr_addr.sin_addr.s_addr = INADDR_ANY; /* Any incoming interface */
    srvr_addr.sin_port = htons(SRVR_PORT);				/* listen port */

    /* Bind to the local address */
	//XXX implement call to bind to listen for incoming messages on your SRVR_PORT
    if (bind(XXXXX) == SOCKET_ERROR)
	{
        fprintf(stderr, "bind() failed due to %d\n",GetLastError());

		// Since we've already opened the socket, we must shut it down and
		// close it appropriately.
		shutdown(srvr_sock, SD_BOTH);
		closesocket(srvr_sock);
		return(-1);
	}

	for(;;)/* Run forever */
    {
        // Set the size of the in-out parameter
        clntLen = sizeof(clnt_addr);

		// Receive message from client
		//XXX implement call to recvfrom to receive messages from clients
		if ((bytes_rcvd = recvfrom(XXXXX ) == SOCKET_ERROR)
		{
			if ((err = WSAGetLastError()) != WSAEMSGSIZE)
			{
					fprintf(stderr, "recvfrom() failed due to %d\n", err);
					shutdown(srvr_sock, SD_BOTH);
					closesocket(srvr_sock);
					return(-1);
			}
		} else	{
			printf("Message: %s from %s:%d\n",
					recv_buf,
					inet_ntoa(clnt_addr.sin_addr), 
					ntohs(clnt_addr.sin_port));
		}
    }
	// not reached
}
