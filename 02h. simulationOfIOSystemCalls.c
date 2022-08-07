#include<sys/types.h>

#include<sys/stat.h>

#include<fcntl.h>

#include<stdlib.h>

#include<stdio.h>

int main() {
  int fd;
  char buf1[100], fname[30];
  printf("Enter the filename:");
  scanf("%s", fname);
  fd = open(fname, O_RDONLY);
  read(fd, buf1, 30);
  printf("\n The content is %s:", buf1);
  close(fd);
}

/*
output:

[it3@localhost ~]$ cc 
io.c 
[it3@localhost ~]$ ./a.out 
Enter the filename:f1
The content is : hi Hello
*/