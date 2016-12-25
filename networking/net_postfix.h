#ifndef NET_POSTFIX
#define NET_POSTFIX
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

int create_listener(char *ipaddress, int port)
{
  struct sockaddr_in address;
  int fd = 0;

  // create socket
  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd < 0)
  {
    return -1;
  }

  memset(&address, 0, sizeof(address));

  // set up address info
  address.sin_family = AF_INET;
  inet_aton(ipaddress, &(address.sin_addr));
  address.sin_port = htons(port);

  // set socket reuse
  int enable = 1;
  if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
  {
    return -1;
  }

  int result = bind(fd, (struct sockaddr *)&address, sizeof(address));
  if (result < 0)
  {
    return -1;
  }

  if (setnonblocking(fd) < 0)
  {
    return -1;
  }

  return fd;
}

int inline setnonblocking(int fd)
{

  int opts = fcntl(fd, F_GETFL);
  if (opts < 0)
    return -1;

  opts = opts | O_NONBLOCK;

  int result = fcntl(fd, F_SETFL, opts);
  if (result < 0)
    return -1;
}
#endif