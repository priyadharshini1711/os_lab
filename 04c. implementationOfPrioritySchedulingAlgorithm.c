#include<stdio.h>

int main() {
  int t[20], p[20], pro[20], temp, wait[20], turn[20], tot_wait = 0, totturn = 0, i, j, n;
  float avgwait = 0, avgturn = 0;
  printf("Enter the no. of processes:");
  scanf("%d", & n);
  for (i = 1; i <= n; i++) {
    printf("\nEnter burst time for process %d:", i);
    scanf("%d", & t[i]);
    printf("\nEnter priority for process %d:", i);
    scanf("%d", & p[i]);
    pro[i] = i;
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (p[j] > p[i]) {
        temp = p[j];
        p[j] = p[i];
        p[i] = temp;
        temp = t[j];

        t[j] = t[i];
        t[i] = temp;
        temp = pro[j];
        pro[j] = pro[i];
        pro[i] = temp;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    wait[i] = 0;
    for (j = 1; j < i; j++) {
      wait[i] += t[j];
    }
    tot_wait += wait[i];
    turn[i] = wait[i] + t[j];
    totturn += turn[i];
  }
  printf("\n\nProcess\tBurst time\tPriority\tWaiting time\tTurnaround time");
  for (i = 1; i <= n; i++) {
    printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", pro[i], t[i], p[i], wait[i], turn[i]);
  }
  printf("\n\n\t\t\tGANTT CHART\n");
  printf("\n	\n");
  for (i = 1; i <= n; i++)
    printf("|\tP%d\t", pro[i]);
  printf("|\t\n");
  printf("\n	\n");
  printf("\n");
  for (i = 1; i <= n; i++) printf("%d\t\t", wait[i]);
  printf("%d", wait[n] + t[n]);
  printf("\n	\n");
  printf("\n");
  printf("\n\nTotal waiting time=%d\nAverage waiting time=%f\n\n", tot_wait, (float) tot_wait / n);
  printf("\n\nTotal turnaround time=%d\n Average turnaround time=%f\n\n", totturn, (float) totturn / n);
}

/*
output

Enter the no. of processes:5

Enter burst time for process 1:3

Enter priority for process 1:1

Enter burst time for process 2:5

Enter priority for process 2:2

Enter burst time for process 3:8

Enter priority for process 3:1

Enter burst time for process 4:5

Enter priority for process 4:4

Enter burst time for process 5:8

Enter priority for process 5:3


Process	Burst time	Priority	Waiting time	Turnaround time
1		3		1		0		3
3		8		1		3		11
2		5		2		11		16
5		8		3		16		24
4		5		4		24		29

			GANTT CHART

	
|	P1	|	P3	|	P2	|	P5	|	P4	|	

	

0		3		11		16		24		29
	



Total waiting time=54
Average waiting time=10.800000



Total turnaround time=83
Average turnaround time=16.600000
*/