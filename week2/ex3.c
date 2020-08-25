#include <stdio.h>

int main(int argc, char *argv[]) {
    int n;
    if (sscanf(argv[1], "%d", &n) != 1) {
        printf("Wrong parameter value!\n");
        return -1;
    }

    int width = 2 * n - 1;
    int stars = -1;
    int spaces = 0;
    for (int i = 0; i < n; i++) {
        stars = stars + 2;
        spaces = (width - stars) / 2;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }

        for (int j = 0; j < stars; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
