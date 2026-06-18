#include<stdio.h>
void main()
	{
	int i,j,n,tq,wt[20]={0},tt[20]={0},ct[20]={0},bt[20][3],temp[20][2],P[10];
	float avgwt,avgtt;
	printf("Enter no of processes:");
	scanf("%d",&n);
	printf("Enter burst time and arrival time(in order) of load process:\n");
	for(i=0;i<n;i++)
		{
		printf("P[%d]:",i);
		bt[i][0]=i;
		scanf("%d%d",&bt[i][1],&bt[i][2]);
		temp[i][1]=bt[i][1];
		}
	wt[0]=0;
	ct[0]=bt[0][1];
	tt[0]=ct[0]-bt[0][2];
	printf("process no:\t\tburst time\t\twaiting time\t\tturnaround time\t\tcomplete time\n");
	for(i=0;i<n;i++)
		{
		printf("P[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",bt[i][0],bt[i][1],wt[i],tt[i],ct[i]);
		wt[i+1]=wt[i]+bt[i][1];
		ct[i+1]=wt[i+1]+bt[i+1][1];
		tt[i+1]=ct[i+1]-bt[i+1][2];
		}
	for(i=0;i<n;i++)
		{
		avgwt+=wt[i];
		avgtt+=tt[i];
		}
	avgwt=avgwt/i;
	avgtt=avgtt/i;
	printf("avg waiting time=%f\n",avgwt);
	printf("avg turnaround time=%f",avgtt);
	}
