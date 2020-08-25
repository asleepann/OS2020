#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    printf("Input two integers, please\nExample: 1 2\n");
    int a;
    int b;
    scanf("%d %d", &a, &b);
    printf("Your input: a = %d; b = %d\n", a, b);
    swap(&a, &b);
    printf("a and b now swapped\nOutput: a = %d; b = %d\n", a, b);
    return 0;
}
