#include <stdio.h>
 
int main() {
    int n, at[100], bt[100], ct[100], tat[100], wt[100];
    float avtat = 0, avwt = 0;
    /**
     * n - number of processes
     * at - arrival time
     * bt - burst time
     * ct - completion time
     * tat - turnaround time
     * wt - waiting time
     * avtat - average turnaround time
     * avwt - average waiting time
     **/
    printf("Enter total number of processes(maximum 100): ");
    scanf("%d", &n);

    // read process at
    printf("\nEnter Process Arrival Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        scanf("%d", &at[i]);
    }
 
    // read process bt
    printf("\nEnter Process Burst Time\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: ", i);
        scanf("%d", &bt[i]);
    }
 
    // sort at array in ascending order (and bt array change respectively)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                int temp1 = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp1;
            }
        }
    }

    wt[0] = 0; // wt for 0 process (first) is 0
    ct[0] = at[0] + wt[0] + bt[0]; // ct for the first process
    tat[0] = ct[0] - at[0]; // tat for the first process
    avtat += tat[0];
    avwt += wt[0];
 
    // calculating wt, ct, tat of processes 1-n
    for (int i = 1; i < n; i++) {
        if (at[i] >= ct[i - 1]) {
            wt[i] = 0;
        } else {
            wt[i] = ct[i - 1] - at[i];
        }
        
        ct[i] = at[i] + wt[i] + bt[i];
        tat[i] = ct[i] - at[i];
        avtat += tat[i];
        avwt += wt[i];
    }

    // calculating avtat and avwt
    avtat /= n;
    avwt /= n;
 
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
 
    // output
    for(int i = 0; i < n; i++) {
        printf("\nP[%d]\t%d\t%d\t%d\t%d\t%d", i, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
 
    printf("\nAverage Turnaround Time: %.2f", avtat);
    printf("\nAverage Waiting Time: %.2f\n", avwt);

    return 0;
}
