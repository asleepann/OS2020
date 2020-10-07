#include <stdio.h>
#include <sys/resource.h>

int main() {
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(1024 * 1024 * 10);
        memset(ptr, 0, 1024 * 1024 * 10);

        int who = RUSAGE_SELF;
        struct rusage usage;
        int ret;
        ret = getrusage(who, &usage);
        printf("%d\n", usage.ru_maxrss);

        sleep(1);
    }

    return 0;
}

/**
 * Program output:
11384
21712
32008
42304
52600
62896
72928
83224
93520
103816
 **/