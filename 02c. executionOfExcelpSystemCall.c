#include<stdio.h>

#include<unistd.h>

#include<sys/wait.h>

#include <stdlib.h>

main() {
  int pid;
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "fork failed\n");
    exit(-1);
  } else if (pid == 0) {
    execlp("/bin/ls", "ls", NULL);
  } else {
    wait(NULL);
    printf("Child Complete");
    exit(0);
  }
}

/*
output
Child Complete
*/