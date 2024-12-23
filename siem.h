#define WIN32_LEAN_AND_MEAN
#define PORT "20000" /* port for server to run on */

#include <stdlib.h> /* std functions */
#include <stdio.h> /* printing functionality */
#include <winsock2.h> /* server */
#include <windows.h>

// link with ws2_32.lib for network functionality
#pragma comment (lib, "Ws2_32.lib")

struct User {
    /* represents a user */

    int uid; /* user ID */
    char* username;
}

struct Location {
    /* represents a location */

    int longitude;
    int latitude;
    char* city;
}

struct Event {
    /* represents an event */

    int numb; /* number of event */
    struct* User user; /* user that the event is related to */
    struct* Location location; /* location of the event */
}


/* logs an event to the database */
void logEvent(struct* Event);

/* fetches report of the database */
void fetchReport(int reportType);

