#ifndef EPOLL
#define EPOLL
#include <sys/epoll.h>

struct epoll_event ev;

int create_loop()
{
  int epfd = epoll_create1(EPOLL_CLOEXEC);

  return epfd;
}

void register_socket(int loop_descriptor, int sockd)
{
  ev.data.fd = sockd;
  ev.data.events = EPOLLIN | EPOLLET;
  epoll_ctl(loop_descriptor, EPOLL_CTL_ADD, sockd, &ev);
}

#endif
