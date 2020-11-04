#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    FILE* instream = fopen(stdin, "r"); // open stdin for reading

    int append;
    if(argc > 1 && strcmp(argv[1], "-a") == 0) // select append option
        append = 1;
    else
        append = 0;

    FILE*filesToWrite[argc - 1 - append]; // files for future

    char mod[1];
    if (append == 0) // select mode of writing into files
        mod[0] = 'w';
    else
        mod[0] = 'a';

    for (int i = append + 1; i < argc; i++) //  open all files
        filesToWrite[i - append - 1] = fopen(argv[i], mod);

    char buf; // buffer to read
    while(read(instream, &buf, 1) != 0){
        printf("%c", buf); // print to stdout
        for (int i = append + 1; i < argc; i++){
            fprintf(filesToWrite[i - append - 1], "%c", buf); // print to files
        }
    }
    for (int i = append + 1; i < argc; i++){ // carefully close files
        fclose(filesToWrite[i - append - 1]);
    }
    return 0;
}
