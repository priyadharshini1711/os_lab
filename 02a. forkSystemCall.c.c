#include<stdio.h>
#include<unistd.h>

main() {
  fork();
  printf("Hello World\n");
}

/*
output:

Hello World
Hello World
*/