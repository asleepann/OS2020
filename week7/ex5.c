#include <stdio.h>

int main() {
    char **s = malloc(sizeof(char*)); // We need to allocate memory for pointer to pointer using malloc
    char foo[] = "Hello World";

    *s = foo;
    printf("s is %p\n", s); // Print pointer - "%p", not "%s"
    s[0] = foo;
    printf("s[0] is %s\n", s[0]);

    return(0);
}
