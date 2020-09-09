#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Hello!\n");
    char input_command[1000];

    while (1) {
        printf("Write command, please: ");

        if (fgets(input_command, 1000, stdin) != NULL) {
            if (input_command[0] == 'e' && input_command[1] == 'x' 
            && input_command[2] == 'i' && input_command[3] == 't') {
                printf("Goodbye!\n");
                return 0;
            } else {
                system(input_command);
            }
        } else {
            printf("Input error.");
        }
    }
    
    return 0;
}
