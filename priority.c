#include<stdio.h>
void main()
	{
	int i,j,n,wt[20],tt[20],ct[20],bt[20][3],temp[3];
	float avgwt,avgtt;
	printf("Enter no: of processes:\n");
	scanf("%d",&n);
	printf("Enter burst time and priority of each processes:\n");
	for(i=0;i<n;i++)
		{
		printf("P[%d]:",i);
		bt[i][0]=i;
		scanf("%d %d",&bt[i][1],&bt[i][2]);
		}
	for(i=0;i<n-1;i++)
		{
		for(j=0;j<n-i-1;j++)
			{
			if(bt[j][2]>bt[j+1][2])
				{
				temp[0]=bt[j][0];
				temp[1]=bt[j][1];
				temp[2]=bt[j][2];
				bt[j][0]=bt[j+1][0];
				bt[j][1]=bt[j+1][1];
				bt[j][2]=bt[j+1][2];
				bt[j+1][0]=temp[0];
				bt[j+1][1]=temp[1];
				bt[j+1][2]=temp[2];
				}
			}
		}
	ct[0]=bt[0][1];
	for(i=1;i<n;i++)
		{
		ct[i]=ct[i-1]+bt[i][1];
		}
	for(i=0;i<n;i++)
		{
		tt[i]=ct[i];
		wt[i]=tt[i]-bt[i][1];
		}
	avgwt=0;
	avgtt=0;
	for(i=0;i<n;i++)
		{
		avgwt+=wt[i];
		avgtt+=tt[i];
		}
	avgwt/=n;
	avgtt/=n;
	printf("\nProcess\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t\t%d\t%d\t%d\n", bt[i][0], bt[i][1], bt[i][2], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtt);
}
