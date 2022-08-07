#include<stdio.h> 

#define n 3

int bu[n], a, in = 1, out = 1, mutex = 1, full = 0, empty = n, x = 0, nc;
main() {
  int ch;
  void producer();
  void consumer();
  int wait(int);
  int signal(int);
  printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
  while (1) {
    printf("\nENTER YOUR CHOICE\n");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      if ((mutex == 1) && (empty > 0)) producer();
      else

        printf("BUFFER IS FULL");
      break;
    case 2:
      if ((mutex == 1) && (full > 0)) consumer();
      else
        printf("BUFFER IS EMPTY");
      break;
    case 3:
      exit(0);
      break;
    }
  }
}
int wait(int s) {
  return (--s);
}
int signal(int s) {
  return (++s);
}
producer() {
  printf("\nEnter the item produced by producer:");
  scanf("%d", & a);
  empty = wait(empty);
  mutex = wait(mutex);
  bu[ in ] = a;
  printf("\nproducer produces the item %d", bu[ in ]); in ++;
  mutex = signal(mutex);
  full = signal(full);
}
void consumer() {
  full = wait(full);
  mutex = wait(mutex);
  nc = bu[out];
  printf("\n consumer consumes item %d", nc);
  out++;
  mutex = signal(mutex);
  empty = signal(empty);
}

/*
output


1.PRODUCER
2.CONSUMER
3.EXIT

ENTER YOUR CHOICE
1

Enter the item produced by producer:10

producer produces the item 10
ENTER YOUR CHOICE
1

Enter the item produced by producer:20

producer produces the item 20
ENTER YOUR CHOICE
2

 consumer consumes item 10
ENTER YOUR CHOICE
2

 consumer consumes item 20
ENTER YOUR CHOICE
2
BUFFER IS EMPTY
ENTER YOUR CHOICE
3

*/