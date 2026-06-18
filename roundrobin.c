#include <stdio.h>

void roundRobin(int processes[], int n, int bt[], int quantum) {
    int rem_bt[n], wt[n], tat[n], time = 0;
    
    // Copy burst times into remaining burst times
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    // Keep processing until all processes are done
    while (1) {
        int done = 1; // Assume all processes are done
        
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // At least one process is not finished

                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done)
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Print results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);

    // Calculate and print average waiting and turnaround times
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
}

int main() {
    int n, quantum;

    // Get number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], bt[n];

    // Get burst times
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Get time quantum
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Execute Round Robin Scheduling
    roundRobin(processes, n, bt, quantum);

    return 0;
}


