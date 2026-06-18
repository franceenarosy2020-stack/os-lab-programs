#include <stdio.h>

void main() {
    int i, j, n, wt[20], tt[20], ct[20], bt[20][4], temp[4];
    float avgwt, avgtt;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, burst time, and priority of each process:\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        bt[i][0] = i; 
        scanf("%d %d %d", &bt[i][1], &bt[i][2], &bt[i][3]);
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j][1] > bt[j + 1][1] || (bt[j][1] == bt[j + 1][1] && bt[j][3] > bt[j + 1][3])) {
                for (int k = 0; k < 4; k++) {
                    temp[k] = bt[j][k];
                    bt[j][k] = bt[j + 1][k];
                    bt[j + 1][k] = temp[k];
                }
            }
        }
    }

   
    int currentTime = 0;
    for (i = 0; i < n; i++) {
        if (currentTime < bt[i][1]) {
            currentTime = bt[i][1]; 
        }
        ct[i] = currentTime + bt[i][2];
        currentTime = ct[i];

        tt[i] = ct[i] - bt[i][1]; 
        wt[i] = tt[i] - bt[i][2]; 
    }

   
    avgwt = 0;
    avgtt = 0;
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtt += tt[i];
    }
    avgwt /= n;
    avgtt /= n;

    
    printf("\nProcess\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t\t%d\t%d\t%d\n", bt[i][0], bt[i][1], bt[i][2], bt[i][3], ct[i], tt[i], wt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtt);
}


