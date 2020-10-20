#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define n 100 // the largest possible number of files which have the same i-node number
// use it for storing names of such files in array

int main() {
    // open directory "tmp"
    DIR *current_dir = opendir("tmp");

    // read directory "tmp" until there will be no unread files
    struct dirent *current_file;
    while ((current_file = readdir(current_dir)) != NULL) {
        // we don't need to consider current directory (".") or parent directory ("..")
        if (!strcmp(current_file->d_name, ".") || !strcmp(current_file->d_name, "..")) {
            continue;
        }

        int current_i_node = current_file->d_ino; // i-node of the current file

        // open directory "tmp" again to find such files which have the same i-node number as current_file
        DIR *check_dir = opendir("tmp");
        struct dirent *check_file;
        
        char *file_names[n]; // names of the files 
        int i = 0; // number of elements in file_names
        while ((check_file = readdir(check_dir)) != NULL) {
            if (check_file->d_ino == current_i_node) {
                file_names[i] = check_file->d_name;
                i++;
            }
        }

        // if number of files which have the same i-node number as current_file is >= 2
        // (current_i_node with a hard link count of two or more)
        // then current file, print i-node number, and list of all files which have this i-node number
        if (i >= 2) {
            printf("current file: %s\ni-node: %d\nfiles: ", current_file->d_name, current_i_node);
            for (int j = 0; j < i; j++) {
                printf("%s ", file_names[j]);
            }
            printf("\n\n");
        }
    }
    return 0;
}
