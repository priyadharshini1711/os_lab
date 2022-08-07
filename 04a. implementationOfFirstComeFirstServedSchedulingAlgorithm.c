#include<stdio.h>

struct process {

  int btime;
  int wtime;
  int ttime;

}
p[50];

int main() {

  int n, j, i;

  float tot_num = 0.0, tot_turn = 0.0, tot_wait = 0.0, avg_turn =
    0.0, avg_wait = 0.0;
  printf("\nEnter the number of process:");

  scanf("%d", & n);
  for (i = 1; i <= n; i++)

  {

    printf("\nEnter the burst time of each process:");
    scanf("%d", & p[i].btime);
  }

  i = 1;

  p[i].wtime = 0;
  p[i].ttime = p[i].btime;
  tot_wait = p[i].wtime;
  tot_turn = p[i].ttime;
  for (i = 2; i <= n; i++)

  {

    p[i].wtime = p[i - 1].wtime + p[i - 1].btime;

    p[i].ttime = p[i].wtime + p[i].btime;
    tot_wait = tot_wait + p[i].wtime;
    tot_turn = tot_turn + p[i].ttime;

  }

  avg_wait = tot_wait / n;
  avg_turn = tot_turn / n;
  printf("\n\n\t\t\tGANTT CHART\n");

  printf("\n	\n");
  for (i = 1; i <= n; i++)

    printf("|\tp%d\t", i);
  printf("|\t\n");

  printf("\n	\n");

  printf("\n");
  for (i = 1; i <= n; i++)
    printf("%d\t\t", p[i].wtime);

  printf("%d", p[n].wtime + p[n].btime);

  printf("\n	\n");

  printf("\n");

  printf("\nProcess burst time waiting time turnaround time\n");
  for (i = 1; i <= n; i++)

  {

    printf("%5d%10d%15d%15d", i, p[i].btime, p[i].wtime, p[i].ttime);
    printf("\n");

  }

  printf("\nAverage wait time:%f\n", avg_wait);
  printf("\nAverage turnaround time:%f\n", avg_turn);

}

/*
output


Enter the number of process:4

Enter the burst time of each process:5

Enter the burst time of each process:3

Enter the burst time of each process:8

Enter the burst time of each process:2


			GANTT CHART

	
|	p1	|	p2	|	p3	|	p4	|	

	

0		5		8		16		18
	


Process burst time waiting time turnaround time
    1         5              0              5
    2         3              5              8
    3         8              8             16
    4         2             16             18

Average wait time:7.250000

Average turnaround time:11.750000
*/