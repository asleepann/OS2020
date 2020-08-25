#include <stdio.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char str[256] = "";
    printf("Input string with length less than 256, please\n");
    fgets(str, 256, stdin);
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        swap(&str[i], &str[length - i - 1]);
    }
    printf("Reverse of the input string: ");
    puts(str);
    return 0;
}
