#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

int main() {
    struct stat status1;
    int file1 = open("ex1.txt", O_RDONLY); // open file with read permission
    fstat(file1, &status1); // info about ex1.txt
    // map ex1.txt to the address1, so we can read from this file
    char *address1 = mmap(NULL, status1.st_size, PROT_READ, MAP_SHARED, file1, 0);

    struct stat status2;
    int file2 = open("ex1.memcpy.txt", O_RDWR); // open file with read and write permissions
    fstat(file2, &status2); // info about ex1.memcpy.txt
    // map ex1.memcpy.txt to the address2, so we can read and write in this file
    char *address2 = mmap(NULL, status2.st_size, PROT_WRITE, MAP_SHARED, file2, 0);

    ftruncate(file2, status1.st_size); // resize ex1.memcpy.txt to size of the ex1.txt
    memcpy(address2, address1, status1.st_size); // copy text from ex1.txt to ex1.memcpy.txt

    munmap(address1, status1.st_size); // close mapping
    munmap(address2, status1.st_size); // close mapping (ex1.memcpy.txt now has the same size as ex1.txt)
    
    close(file1); // close ex1.txt
    close(file2); // close ex1.memcpy.txt
    return 0;
}
