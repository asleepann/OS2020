#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main () {
    for (int i = 0; i < 3; i++) {
        fork();
    }
    
    sleep(5);

    return 0;
}

/**
 * 8 processes were created.
 * fork() splits each process by 2 every time we call it,
 * so, when we call fork() 3 times we will get 2^3 processes = 8 processes.
**/

/** for 3 iterations
    gnome-terminal-─┬─bash───pstree
                    ├─bash───ex2─┬─ex2─┬─ex2───ex2
                    │            │     └─ex2
                    │            ├─ex2───ex2
                    │            └─ex2
                    └─4*[{gnome-terminal-}]

**/

/** for 5 iterations
    gnome-terminal-─┬─bash───pstree
                    ├─bash───ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
                    │            │     │     │     └─ex2
                    │            │     │     ├─ex2───ex2
                    │            │     │     └─ex2
                    │            │     ├─ex2─┬─ex2───ex2
                    │            │     │     └─ex2
                    │            │     ├─ex2───ex2
                    │            │     └─ex2
                    │            ├─ex2─┬─ex2─┬─ex2───ex2
                    │            │     │     └─ex2
                    │            │     ├─ex2───ex2
                    │            │     └─ex2
                    │            ├─ex2─┬─ex2───ex2
                    │            │     └─ex2
                    │            ├─ex2───ex2
                    │            └─ex2
                    └─4*[{gnome-terminal-}]
**/
