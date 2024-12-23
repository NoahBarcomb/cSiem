#include <stdio.h> /* printing functionality */
#include <winsock2.h> /* server */

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
void logEvent();

/* fetches report of the database */
void fetchReport(int reportType);

