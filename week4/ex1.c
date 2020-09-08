#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main () {
    int n = fork();
    if (n != 0) {
        printf("Hello from parent[%d - %d]\n", getpid(), n);
    } else {
        printf("Hello from child[%d - %d]\n", getpid(), n);
    }
    return 0;
}

/**
Hello from parent[8984 - 8985]
Hello from child[8985 - 0]
Hello from parent[8986 - 8987]
Hello from child[8987 - 0]
Hello from parent[8988 - 8989]
Hello from child[8989 - 0]
Hello from parent[8990 - 8991]
Hello from child[8991 - 0]
Hello from parent[8992 - 8993]
Hello from child[8993 - 0]
Hello from parent[8994 - 8995]
Hello from child[8995 - 0]
Hello from parent[8996 - 8997]
Hello from child[8997 - 0]
Hello from parent[8998 - 8999]
Hello from parent[9000 - 9001]
Hello from child[9001 - 0]
Hello from child[8999 - 0]
Hello from parent[9002 - 9003]
Hello from child[9003 - 0]
**/
