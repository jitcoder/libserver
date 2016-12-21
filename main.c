#include <stdio.h>
#include "networking/networking.h"

int main() {
  int ld = create_listener("0.0.0.0", 3000);

  if(ld < 0){
    printf("create_listener failed...");
    return -1;
  }

  close(ld);

  printf("finished");
}