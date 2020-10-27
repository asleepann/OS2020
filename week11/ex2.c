#include <stdio.h>

int main() {
    setvbuf(stdout, NULL, _IOLBF, NULL); // printing with line buffer
    
    char *str = "Hello";
    for (int i = 0; i < strlen(str); i++) { // print "Hello" by chars with 1 sec sleep after every printf()
        printf("%c", str[i]);
        sleep(1);
    }

    return 0;
}
