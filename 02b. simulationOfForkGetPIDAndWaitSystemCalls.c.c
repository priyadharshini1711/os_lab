#include<stdio.h>

#include<unistd.h>

#include<stdlib.h>

#include<conio.h>

main() {
  int a = -1, b = 1, i, c = a + b, n, pid, cpid;
  printf("\nenter no. of terms ");
  scanf("%d", & n);
  pid = getpid();
  printf("\nparent process id is %d", pid);
  pid = fork();
  cpid = getpid();
  printf("\nchild process:%d", cpid);
  if (pid == 0) {
    printf("\nchild is producing fibonacci series ");
    for (i = 0; i < n; i++) {
      c = a + b;
      printf("\n%d", c);
      a = b;
      b = c;
    }
    printf("\nchild ends");
  } else {
    printf("\nparent is waiting for child to complete");

    wait(NULL);
    printf("\nparent ends");
  }
}

/*
output

enter no. of terms 5
parent process id is 18953
child process:18953
parent process id is 18953
child process:18958
child is producing fibonacci series 
0
1
1
2
3
child endsparent is waiting for child to complete
parent ends
*/