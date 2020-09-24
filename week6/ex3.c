#include <stdio.h>
 
int main() {
    int n, q, at[100], bt[100], bt1[100], ct[100], tat[100], wt[100], ended[100], done = 0;
    float avtat = 0, avwt = 0;
    /**
     * n - number of processes
     * q - quantum
     * at - arrival time
     * bt - burst time
     * bt1 - burst time remaining after partial execution
     * ct - completion time
     * tat - turnaround time
     * wt - waiting time
     * avtat - average turnaround time
     * avwt - average waiting time
     * ended - 0 if process is not ended, 1 otherwise
     * done - number of ended processes
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

    // read quantum
    printf("\nEnter Quantum: ");
    scanf("%d", &q);
 
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

    for (int i = 0; i < n; i++) {
        bt1[i] = bt[i];
    }

    // at start all processes is not ended
    for (int i = 0; i < n; i++) {
        ended[i] = 0;
    }

    // calculating wt, ct, tat of processes 0-n
    int currentTime = 0;
    // while not all tasks are done
    while (done != n) {
        int current = -1;

        // going around tasks
        for (int i = 0; i < n; i++) {
            // if this task is pending, perform it
            if (at[i] <= currentTime && ended[i] == 0) {
                current = i;
                // if remaining execution time is less or equal than quantum, complete it
                if (bt1[current] <= q) {
                    ended[current] = 1;
                    ct[current] = currentTime + bt1[current];
                    tat[current] = ct[current] - at[current];
                    wt[current] = tat[current] - bt[current];
                    avtat += tat[current];
                    avwt += wt[current];

                    done += 1;
                    currentTime += bt1[current];
                // otherwise partially execute it and switch to another task
                } else {
                    bt1[current] -= q;
                    currentTime += q;
                }
            }
        }

        // if there are no pending tasks, search for earliest to come next
        if (current == -1) {
            for (int i = 0; i < n; i++) {
                if (at[i] > currentTime) {
                    current = i;
                    // if remaining execution time is less or equal than quantum, complete it
                    if (bt1[current] <= q) {
                        ended[current] = 1;
                        ct[current] = currentTime + bt1[current];
                        tat[current] = ct[current] - at[current];
                        wt[current] = tat[current] - bt[current];
                        avtat += tat[current];
                        avwt += wt[current];

                        done += 1;
                        currentTime += bt1[current];
                    // otherwise partially execute it and switch to another task
                    } else {
                        bt1[current] -= q;
                        currentTime += q;
                    }
                    break;
                }
            }
        }
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
