#include<stdio.h> 

int main()
{
  int fd[2], child;
  char a[20];
  printf("\nEnter the string to enter into the pipe:");
  scanf("%s", a);
  pipe(fd);
  child = fork();
  if (!child) {
    close(fd[0]);
    write(fd[1], a, 5);
  } else {
    close(fd[1]);
    read(fd[0], a, 5);
    printf("\n The string retrieved from the pipe is %s\n", a);
  }
  return 0;
}

/*
output


Enter the string to enter into the pipe:operatingsystem

 The string retrieved from the pipe is operatingsystem
*/