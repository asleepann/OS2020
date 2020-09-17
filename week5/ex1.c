#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10

pthread_t thread_id[NUM_THREADS];

void* PrintHello(int* i) {
    printf("\nHello from thread %d - I was created in iteration %d !\n",
        (int) pthread_self(), *i);
    // The function's return value serves as the thread's exit status
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) { 
    int rc, i;
    for (i = 0; i < NUM_THREADS; i++) {
        // Create a new thread that will execute 'PrintHello'
        rc = pthread_create(&thread_id[i], NULL, PrintHello, &i);

        pthread_join(thread_id[i], NULL);

        printf("\nI am thread %d. Created new thread (%d) in iteration %d\n",
            (int) pthread_self(), (int) thread_id[i], i);
        if (rc) {         
            printf("\nERROR: return code from pthread_create is %d \n", rc);         
            exit(1);      
        }
    }
    pthread_exit(NULL);
}

/**
 * We get such result (mixed order of outputs) because we do not know actual order of execution of created threads,
 * it depends on scheduler's work. We use pthread_join() to fix this problem.
 * 
 * Mixed output:

I am thread -1088825536. Created new thread (-1088829696) in iteration 0

Hello from thread -1088829696 - I was created in iteration 0 !

I am thread -1088825536. Created new thread (-1097222400) in iteration 1

I am thread -1088825536. Created new thread (-1105615104) in iteration 2

Hello from thread -1105615104 - I was created in iteration 3 !

I am thread -1088825536. Created new thread (-1207961856) in iteration 3

I am thread -1088825536. Created new thread (-1114118400) in iteration 4

I am thread -1088825536. Created new thread (-1122511104) in iteration 5

Hello from thread -1097222400 - I was created in iteration 5 !

Hello from thread -1122511104 - I was created in iteration 6 !

Hello from thread -1114118400 - I was created in iteration 5 !

I am thread -1088825536. Created new thread (-1130903808) in iteration 6

Hello from thread -1207961856 - I was created in iteration 5 !

I am thread -1088825536. Created new thread (-1216354560) in iteration 7

Hello from thread -1216354560 - I was created in iteration 7 !

I am thread -1088825536. Created new thread (-1224747264) in iteration 8

Hello from thread -1130903808 - I was created in iteration 6 !

I am thread -1088825536. Created new thread (-1233139968) in iteration 9

Hello from thread -1233139968 - I was created in iteration 9 !

Hello from thread -1224747264 - I was created in iteration 10 !


 * Ordered output:

Hello from thread 739321600 - I was created in iteration 0 !

I am thread 739325760. Created new thread (739321600) in iteration 0

Hello from thread 739321600 - I was created in iteration 1 !

I am thread 739325760. Created new thread (739321600) in iteration 1

Hello from thread 739321600 - I was created in iteration 2 !

I am thread 739325760. Created new thread (739321600) in iteration 2

Hello from thread 739321600 - I was created in iteration 3 !

I am thread 739325760. Created new thread (739321600) in iteration 3

Hello from thread 739321600 - I was created in iteration 4 !

I am thread 739325760. Created new thread (739321600) in iteration 4

Hello from thread 739321600 - I was created in iteration 5 !

I am thread 739325760. Created new thread (739321600) in iteration 5

Hello from thread 739321600 - I was created in iteration 6 !

I am thread 739325760. Created new thread (739321600) in iteration 6

Hello from thread 739321600 - I was created in iteration 7 !

I am thread 739325760. Created new thread (739321600) in iteration 7

Hello from thread 739321600 - I was created in iteration 8 !

I am thread 739325760. Created new thread (739321600) in iteration 8

Hello from thread 739321600 - I was created in iteration 9 !

I am thread 739325760. Created new thread (739321600) in iteration 9
**/
