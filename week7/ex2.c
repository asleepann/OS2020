#include <stdio.h>

int main() {
    printf("Enter the size of the array: ");
    int n;
    scanf("%d", &n);

    // allocate memory for the array
    int *array = malloc(n * sizeof(int));

    // fill the array
    for (int i = 0; i < n; i++) {
        array[i] = i;
    }

    // print the array
    printf("Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }

    // deallocate memory
    free(array);

    return 0;
}
