#include "net_postfix.h"

int create_listener(char* ipaddress, int port) {
  struct sockaddr_in address;
  int fd = 0;

  // create socket
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd  < 0){
    return -1;
  }

  memset(&address, 0, sizeof(address));

  // set up address info
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(ipaddress);
  address.sin_port = htons(port);

  // set non-blocking
  int opts;
  if ((opts = fcntl(fd, F_GETFL)) < 0){
    opts = opts | O_NONBLOCK;
    fcntl(fd, F_SETFL, opts);
  } else {
    return -1;
  }

  // set socket reuse
  int enable = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0){
    return -1;
  }

  int result = bind(fd, (struct sockaddr *)&address, sizeof(address));
  if(result < 0){
    return -1;
  }

  return fd;
}
