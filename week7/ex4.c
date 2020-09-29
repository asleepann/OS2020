#include <stdio.h>

void *myRealloc(void *ptr, size_t size) {
    if (ptr == NULL) {
        return malloc(size);
    } else if (size == 0) {
        free(ptr);
        return NULL;
    } else {
        void *a = malloc(size);
        a = memcpy(a, ptr, size); // copy elements to the new memory fields
        free(ptr); // free originally allocated memory
        return a;
    }
}

int main() {
    // test meRealloc() by using ex3
    printf("Enter original array size: ");
	int n1;
	scanf("%d", &n1);

	int* a1 = malloc(n1 * sizeof(int));
	printf("Array with original size:\n");
	for (int i = 0; i < n1; i++) {
		a1[i] = 100;
		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2;
	scanf("%d", &n2);

	a1 = myRealloc(a1, n2 * sizeof(int));

    if (n2 > n1) {
        for (int i = n1; i < n2; i++) {
            a1[i] = 0;
        }
    }

    printf("Array with new size:\n");
	for (int i = 0; i < n2; i++) {
		printf("%d ", a1[i]);
	}
	printf("\n");

    return 0;
}
