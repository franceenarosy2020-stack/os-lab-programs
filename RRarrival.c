#include <stdio.h>
void roundRobin(int processes[], int n, int bt[], int at[], int quantum) 
	{
	int remaining_bt[n], wt[n], tat[n], time = 0, completed = 0;
	for (int i = 0; i < n; i++) 
		{
		remaining_bt[i] = bt[i]; 
		wt[i] = 0; 
		}
	while (completed < n) 
		{
		 int executed = 0;
		 for (int i = 0; i < n; i++)
			{
			if (remaining_bt[i] > 0 && at[i] <= time) 
				{ 
		        	if (remaining_bt[i] > quantum) 
		        		{
					 time += quantum;
					 remaining_bt[i] -= quantum;
					} 
				else 
					{
					 time += remaining_bt[i];
					 wt[i] = time - bt[i] - at[i]; 
					 remaining_bt[i] = 0;
					 completed++;
		        		}
				executed = 1;
				}
			}
		if (!executed)
			time++; 
		}
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
	printf("\nProcess\tAT\tBT\tWT\tTAT\n");
	for (int i = 0; i < n; i++)
        	printf("%d\t%d\t%d\t%d\t%d\n", processes[i], at[i], bt[i], wt[i], tat[i]);
	float total_wt = 0, total_tat = 0;
	for (int i = 0; i < n; i++) 
		{
		total_wt += wt[i];
		total_tat += tat[i];
    		}
	printf("\nAverage Waiting Time: %.2f", total_wt / n);
	printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
	}

int main() 
	{
	int n, quantum;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	int processes[n], bt[n], at[n];
	for (int i = 0; i < n; i++) 
		{
		processes[i] = i + 1;
		printf("Enter arrival time for process %d: ", i + 1);
		scanf("%d", &at[i]);
		printf("Enter burst time for process %d: ", i + 1);
		scanf("%d", &bt[i]);
		}
	printf("Enter time quantum: ");
	scanf("%d", &quantum);
	roundRobin(processes, n, bt, at, quantum);
	
	
	return 0;
	} 
