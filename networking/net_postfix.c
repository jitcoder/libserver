#include "net_postfix.h"

int create_listener(char* ipaddress, int port){
  struct sockaddr_in address;
  int fd = 0;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd  < 0){
    return fd;
  }

  memset(&address, '0', sizeof(address));

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(ipaddress);
}