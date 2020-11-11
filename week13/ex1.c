#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *input;
    input = fopen("input.txt", "r");

    int n = 0; // number of processes
    fscanf(input, "%d", &n);
    int m = 0; // number of types of resources
    fscanf(input, "%d", &m);

    // declaration of needed vectors and matrices
    int *E = (int*)malloc(sizeof(int) * m); // resources in existence
    int *A = (int*)malloc(sizeof(int) * m); // resources available
    int **C = (int**)malloc(sizeof(int*) * n); // current allocation matrix
    int **R = (int**)malloc(sizeof(int*) * n); // request matrix

    for (int i = 0; i < n; i++) {
        C[i] = (int*)malloc(sizeof(int) * m);
        R[i] = (int*)malloc(sizeof(int) * m);
    }

    // fill in vectors and matrices with input data
    for (int i = 0; i < m; i++) {
        fscanf(input, "%d", &E[i]);
    }

    for (int i = 0; i < m; i++) {
        fscanf(input, "%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &C[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &R[i][j]);
        }
    }

    fclose(input);

    // array of processes states:
    // if i-th process is marked then P[i] = 1,
    // otherwise P[i] = 0.
    // at the beggining all processes are unmarked
    int *P = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        P[i] = 0;
    }

    int marked = 0; // number of marked processes
    while (marked != n) { // the loop will end when all processes have been reviewed
        int current_process = -1; // number of the process that satisfies constraints below

        // find unmarked process i, for which the R[i][j] <= A[j] for 0 <= j < m
        for (int i = 0; i < n; i++) {
            int less_or_equal = 0; // number of types of resources such that R[i][j] <= A[j]

            for (int j = 0; j < m; j++) {
                if (R[i][j] <= A[j]) {
                    less_or_equal++;
                }
            }

            // if process is unmarked and all its requests can be solved
            if (P[i] == 0 && less_or_equal == m) {
                current_process = i;
                P[i] = 1;
                marked++;
                break;
            }
        }

        // if process with needed conditions was found,
        // it means that this process is able to complete and it is not deadlocked,
        // so, when the process is finished, it returns the resources it is holding
        // to the pool of available resources: A[i] += C[current_process][i]
        if (current_process != -1) {
            for (int i = 0; i < m; i++) {
                A[i] += C[current_process][i];
            }
        }
        else { // if process was not found
            printf("Deadlock is detected! Deadlocked processes:\n");
            for (int i = 0; i < n; i++) {
                if (P[i] == 0) {
                    printf("%d\n", i + 1); // indexes of processes that are deadlocked
                }
            }
            return 0; // deadlock detected, therefore, program must terminate
        }
    }

    printf("No deadlocks is detected!\n"); // all processes are marked, therefore, there is no deadlocks

    return 0;
}
