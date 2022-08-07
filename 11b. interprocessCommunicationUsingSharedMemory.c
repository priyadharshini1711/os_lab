#include<stdio.h> 
#include<unistd.h> 
#include<sys/ipc.h> 
#include<sys/shm.h> 
#include<sys/types.h> 
#include<fcntl.h> 

int main()

{
  char * shmptr;
  int shmid, child, i;
  shmid = shmget(2041, 30, IPC_CREAT | 0666);
  shmptr = shmat(shmid, 0, 0);
  child = fork();
  if (!child) {
    printf("PARENT WRITING\n");
    for (i = 0; i < 20; i++) {
      shmptr[i] = 'a' + i;
      putchar(shmptr[i]);
    }
    wait(0);
  } else {

    printf("\nCHILD READING\n");
    for (i = 0; i < 20; i++) putchar(shmptr[i]);
    shmdt(NULL);
    shmctl(shmid, IPC_RMID, 0);
  }
}

/*
output


CHILD READING
PARENT WRITING
abcdefghijklmnopqrst
*/