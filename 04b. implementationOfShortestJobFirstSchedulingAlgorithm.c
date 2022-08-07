#include<stdio.h> 

int main()

{

  int p;
  int n;

  int i, j, tot_wt = 0, tot_tt = 0;

  float avg_wt = 0.0, avg_tu = 0.0;
  int stt;

  int t, pno[10], bs[10], wt[10], tu[10], ft[10];
  printf("enter the number of process:");
  scanf("%d", & p);

  n = p;
  for (i = 1; i <= n; i++)

  {

    pno[i] = i;

    printf("enter the burst time :");
    scanf("%d", & bs[i]);

  }

  for (i = 1; i <= n; i++)

  {

    for (j = i + 1; j <= n; j++)

    {

      if (bs[i] > bs[j])

      {

        t = pno[i];
        pno[i] = pno[j];
        pno[j] = t;

        t = bs[i];
        bs[i] = bs[j];
        bs[j] = t;

      }

    }

  }

  stt = 0;
  for (i = 1; i <= n; i++)

  {

    ft[i] = stt + bs[i];
    wt[i] = stt;
    tu[i] = wt[i] + bs[i];
    tot_wt = tot_wt + wt[i];
    tot_tt = tot_tt + tu[i];
    stt = ft[i];

  }

  avg_wt = tot_wt / n;
  avg_tu = tot_tt / n;

  printf("\n\n\t\t\tGANTT CHART\n");

  printf("\n	\n");
  for (i = 1; i <= n; i++)

    printf("|\tP%d\t", pno[i]);
  printf("|\t\n");

  printf("\n	\n");

  printf("\n");
  for (i = 1; i <= n; i++)
    printf("%d\t\t", wt[i]);

  printf("%d", wt[n] + bs[n]);

  printf("\n	\n");

  printf("\n");

  printf
    ("pno bursttime(msec)	waitingtime(msec)	turnaroundtime(msec)\n");
  for (i = 1; i <= n; i++)

  {

    printf("%d\t\t%d\t\t%d\t\t%d", pno[i], bs[i], wt[i], tu[i]);
    printf("\n");

  }

  printf("Average waiting time in millisec is");
  printf("\t%f", avg_wt);

  printf("\nAverage turnaround time in millisec ");
  printf("\t%f", avg_tu);

}

/*
output

enter the number of process:4
enter the burst time :2
enter the burst time :3
enter the burst time :4
enter the burst time :4


			GANTT CHART

	
|	P1	|	P2	|	P3	|	P4	|	

	

0		2		5		9		13
	

pno bursttime(msec)	waitingtime(msec)	turnaroundtime(msec)
1		2		0		2
2		3		2		5
3		4		5		9
4		4		9		13
Average waiting time in millisec is	4.000000
Average turnaround time in millisec 	7.000000
*/
