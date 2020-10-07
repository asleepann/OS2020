#include <stdio.h>

int main() {
    for (int i = 0; i < 10; i++) {
        void* ptr = malloc(1024 * 1024 * 10);
        memset(ptr, 0, 1024 * 1024 * 10);
        sleep(1);
    }

    return 0;
}

/**
 * ex3 is a CPU-intensive task because it is in the list below (5 row of the table).
 * 
top - 15:54:35 up  2:10,  1 user,  load average: 0,34, 0,30, 0,19
Tasks: 234 total,   1 running, 225 sleeping,   8 stopped,   0 zombie
%Cpu(s):  3,0 us,  1,7 sy,  0,0 ni, 94,8 id,  0,0 wa,  0,0 hi,  0,5 si,  0,0 st
MiB Mem :   5868,0 total,    234,8 free,   1922,0 used,   3711,2 buff/cache
MiB Swap:   1131,1 total,   1131,1 free,      0,0 used.   3482,8 avail Mem 

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND                                       
   8077 anna      20   0 3039140 306848 150384 S   4,0   5,1   5:22.15 MainThread                                    
   7585 anna      20   0   18,9g 272172 115336 S   3,0   4,5   3:40.95 code                                          
   8395 anna      20   0 2501940 168260 107348 S   2,0   2,8   3:10.07 file:// Content                               
   9483 anna      20   0 2254176 274092 104372 S   2,0   4,6   0:12.35 telegram-deskto                               
   9803 anna      20   0   63952  62724   1196 S   2,0   1,0   0:00.07 ex3                                           
      1 root      20   0  169228  13100   8276 S   1,0   0,2   0:06.13 systemd                                       
   6026 anna      20   0  791744  89844  57588 S   1,0   1,5   0:39.99 Xorg                                          
   9307 root      20   0       0      0      0 I   1,0   0,0   0:00.13 kworker/3:0-events                            
   9804 anna      20   0   20628   4016   3228 R   1,0   0,1   0:00.07 top                                           
      2 root      20   0       0      0      0 S   0,0   0,0   0:00.00 kthreadd                                      
      3 root       0 -20       0      0      0 I   0,0   0,0   0:00.00 rcu_gp                                        
      4 root       0 -20       0      0      0 I   0,0   0,0   0:00.00 rcu_par_gp                                    
 **/