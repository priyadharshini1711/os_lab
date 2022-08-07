#include<stdio.h>

#include<stdlib.h>

main() {
  int pid;
  pid = getpid();
  printf("\n  the current process id is %d", pid);
  pid = fork();
  if (pid == 0) {
    printf("\n child starts");
    printf("\n child completed");
  } else {
    sleep(10);
    printf("\n parent process running");
    printf("\n i am in zoombie state");
  }
}

/*
output

the current process id is 7944
 child starts
 child completedthe current process id is 7944
 parent process running
 i am in zoombie state
*/