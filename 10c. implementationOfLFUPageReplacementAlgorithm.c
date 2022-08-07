#include<stdio.h> 
#include<conio.h> 
struct frame

{
  int val;
  int freq;
  int pos;
}
f[30];
int no_frame, no_page, page_seq[100], page_fault = 0;
void input() {
  int i;
  printf("\n\n least freqently used\n");
  printf("\n enter no_of frame:");
  scanf("%d", & no_frame);
  printf("\n enter no_of pages:");
  scanf("%d", & no_page);
  printf("enter page sequence:");
  for (i = 0; i < 3; i++) scanf("%d", & page_seq[i]);
  printf("\n");
  for (i = 0; i < 3; i++) {
    f[i].pos = -1;
    f[i].val = -1;
    f[i].freq = 0;

  }
}
void display() {
  static int preev_page_fault = 0;
  int i;
  for (i = 0; i < 3; i++) {
    if (f[i].val == -1) {
      printf("0");
    } else {
      printf("%d", f[i].val);
    }
  }
  if (preev_page_fault != page_fault) {
    printf("F");
    preev_page_fault = page_fault;
  }
  printf("\n");
}
int search(int i) {
  int j;
  for (j = 0; j < 3; j++) {
    if (f[j].val == page_seq[i]) return j;
  }
  return -1;
}
int position() {
  int i, j = 0, k;
  for (i = 0; i < 3; i++) {
    if (f[i].pos == -1) return i;
  }
  for (i = 0; i < 3; i++) {
    if (f[j].freq > f[i].freq) {

      j = i;
    }
  }
  k = j;
  for (i = 0; i < 3; i++) {
    if (f[j].freq == f[i].freq && j != i) {
      if (f[j].pos > f[i].pos) j = i;
    }
    k = j;
    return k;
  }
  return 0;
}
void LFU() {
  int i, k;
  input();
  for (i = 0; i < 3; i++) {
    k = search(i);
    if (k != -1) {
      f[k].freq++;
      f[k].pos = i;
    }
    if (k == -1) {
      k = position();
      f[k].pos = i;
      f[k].val = page_seq[i];
      f[k].freq = 1;
      page_fault++;
    }
    display();
  }
}
int main() {
  LFU();
  printf("\n no.of page faults %d", page_fault);
}

/*
output


 least freqently used

 enter no_of frame:3

 enter no_of pages:4
enter page sequence:4
5
8

400F
450F
458F

 no.of page faults 3
*/