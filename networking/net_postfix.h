#define NET_POSTFIX
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int create_listener(char* ipaddress, int port);
