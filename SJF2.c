#include <stdio.h>

void main() {
    int i, j, n, wt[20], tt[20], ct[20], bt[20][2], temp[2];
    float avgwt = 0, avgtt = 0;

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    printf("Enter burst time of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        bt[i][0] = i;
        scanf("%d", &bt[i][1]);
    }

    // Sorting based on burst time using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j][1] > bt[j + 1][1]) {
                // Swapping process numbers
                temp[0] = bt[j][0];
                bt[j][0] = bt[j + 1][0];
                bt[j + 1][0] = temp[0];

                // Swapping burst times
                temp[1] = bt[j][1];
                bt[j][1] = bt[j + 1][1];
                bt[j + 1][1] = temp[1];
            }
        }
    }

    wt[0] = 0;
    ct[0] = bt[0][1];
    tt[0] = ct[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1][1];
        ct[i] = wt[i] + bt[i][1];
        tt[i] = ct[i];
    }

    printf("Process No.\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t\t %d\t\t %d\t\t %d\n", bt[i][0], bt[i][1], wt[i], tt[i]);
        avgwt += wt[i];
        avgtt += tt[i];
    }

    avgwt = avgwt / n;
    avgtt = avgtt / n;

    printf("Avg Waiting Time = %f\n", avgwt);
    printf("Avg Turnaround Time = %f\n", avgtt);
} 
