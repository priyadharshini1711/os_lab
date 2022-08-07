#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>

#include<stdio.h>

#include<string.h>

#include<dirent.h>

main(int argc, char * argv[]) {
  DIR * dp;
  struct dirent * link;
  dp = opendir(argv[1]);
  printf("contents of directory %s are \n", argv[1]);
  while ((link = readdir(dp)) != 0)
    printf("%s", link -> d_name);
  closedir(dp);
}

/*
output

[it27@mm4 aaa]$ cat>>aa 
os[it27@mm4 aaa]$ cat>>bb 
system[it27@mm4 aaa]$ cd .. 
[it27@mm4 ~]$ cc ls.c 
[it27@mm4 ~]$ ./a.out aaa 
contents of directory aaa are
.bb..aa
*/