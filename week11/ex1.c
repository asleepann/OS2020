#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    struct stat status_ex1;
    int ex1_txt = open("ex1.txt", O_RDWR); // open file with read and write permissions
    fstat(ex1_txt, &status_ex1); // info about ex1.txt

    char *new_str = "This is a nice day";
    // map ex1.txt to the address, so we can write in this file
    char *address = mmap(NULL, status_ex1.st_size, PROT_WRITE, MAP_SHARED, ex1_txt, 0);
    ftruncate(ex1_txt, strlen(new_str)); // resize ex1.txt to size of the string new_str
    strncpy(address, new_str, strlen(new_str)); // copy new_str to ex1.txt
    munmap(address, strlen(new_str));
    
    close(ex1_txt); // close file
    return 0;
}
