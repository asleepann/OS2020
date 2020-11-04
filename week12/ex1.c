#include <stdio.h>

int main(){
    FILE* dev_random = fopen("/dev/random", "r"); // open /dev/random for reading
    char random_chars[20];
    fscanf(dev_random, "%20s", &random_chars);// read random characters from it
    fclose(dev_random);
    FILE* ex1_txt = fopen("ex1.txt", "w"); // open file for writing
    fprintf(ex1_txt,"%s",random_chars); // write random chars to that file
    fclose(ex1_txt);
    return 0;
}
