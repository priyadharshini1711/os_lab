#include<stdio.h>

#include<unistd.h>

#include<sys/types.h>

#include<dirent.h>

main(int argc, char * argv[]) {
  DIR * dirname;
  struct dirent * dir;
  dirname = opendir(argv[1]);
  dir = readdir(dirname);
  while (dir != NULL) {
    printf("Entry found :%s\n", dir -> d_name);
    printf("Inode number of entry:%d\n", dir -> d_ino);
    printf("Length of this record:%d\n", dir -> d_reclen);
    getchar();
  }
}

/*
output

[it1@localhost ~]$ cc ex1f.c 
[it1@localhost ~]$ mkdir anu 
[it1@localhost ~]$ cd 
[it1@localhost ~]$ cd anu 
[it1@localhost anu]$ 
cat>>new os is an interface
[it1@localhost anu]$ 
cat>>new1 os is resident 
monitor [it1@localhost anu]$ cd 
[it1@localhost ~]$ ./a.out anu 
Entry found :..
Inode number of entry:26542353 
Length of this record:16 
*/