#include<stdio.h> 

int main()

{
  int n, size, la, i, pno[10], fno[10], offset, pa, limit, p;
  printf("Enter the number of pages:");
  scanf("%d", & n);
  printf("Enter the size of page:");
  scanf("%d", & size);
  limit = n * size - 1;
  printf("Enter logical address within the limit %d:", limit);
  scanf("%d", & la);
  for (i = 0; i < n; i++) {
    printf("Enter the pageno:");
    scanf("%d", & pno[i]);
    printf("Enter the frame no:");
    scanf("%d", & fno[i]);
  }
  printf("pageno\tframeno");
  for (i = 0; i < n; i++) {
    printf("\n%d\t\t%d", pno[i], fno[i]);
  }
  p = la / size;
  printf("\n The page number is %d", p);

  offset = la % size;
  printf("\nOffset is %d", offset);
  pa = fno[p] * size + offset;
  printf("\n The physical address is %d", pa);
}

/*
output
Enter the number of pages:4
Enter the size of page:4
Enter logical address within the limit 15:6
Enter the pageno:0
Enter the frame no:5
Enter the pageno:1
Enter the frame no:3
Enter the pageno:2
Enter the frame no:8
Enter the pageno:3
Enter the frame no:6
pageno	frameno
0		5
1		3
2		8
3		6
 The page number is 1
Offset is 2
 The physical address is 14
*/