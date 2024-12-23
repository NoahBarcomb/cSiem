#include <Winsock2.h>



int main() {

    WSADATA wsaData;

    int result = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (result != 0) {
        printf("WSA Startup Failed: %d\n", result);
        exit(1);
    }

    struct addrinfo *result = NULL, *ptr = NULL, hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    /* reuse result variable */
    result = getaddrinfo(NULL, PORT, &hints, &result);
    if (result != 0) {
        printf("getaddrinfo failed: %d\n", result);
        WSACleanup();
        exit(1);
    }

    /* create server socket */

    SOCKET serverSock = INVALID_SOCKET;

    serverSock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    /* make sure socket is valid */

    if (serverSock == INVALID_SOCKET) {
        printf("socket() error: %ld\n", WSAetLastError());
        freeaddrinfo(result);
        WSACleanup();
        exit(1);
    }


    /* bind socket */

    result = bind(serverSock, result->ai_addr, (int)result->ai_addrlen);

    /* make sure bind call completed successfully */
    if (result == SOCKET_ERROR) {
        printf("bind() error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(serverSock);
        WSACleanup();
        exit(1);
    }

    /* no longer needed */
    freeaddrinfo(result);
    
    while (1) {

    }
}