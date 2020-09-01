#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int array[], int size) { // array[] is a pointer to the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    printf("Enter number of elements in the array, please\n");
    int size;
    scanf("%d", &size);

    printf("Enter elements of the array, please\n");
    int array[1000];
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    bubble_sort(array, size);

    printf("Input array sorted in ascending order:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}
