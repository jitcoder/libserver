#include <stdio.h>
#include "networking/networking.h"
#include "multiplexers/events.h"

int main()
{
  int ld = create_listener("127.0.0.1", 3000);

  if (ld < 0)
  {
    printf("create_listener failed...");
    return -1;
  }

  int eventd = create_loop();

  close(ld);

  printf("finished");
}