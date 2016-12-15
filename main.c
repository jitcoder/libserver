#include <stdio.h>
#include "networking/net_postfix.h"

int main(){
  create_listener("0.0.0.0", 3000);
  printf("hello world!");
}