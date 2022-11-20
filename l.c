#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#define _POSIX_SOURCE
#include <sys/wait.h>

int main (){
    struct timespec ini1, end1;
    clock_gettime(CLOCK_REALTIME, &ini1);
    int id1 = fork();
    struct timespec ini2, end2;
    clock_gettime(CLOCK_REALTIME, &ini2);
    int id2 = fork();
    if(id1 ==0){
        if(id2 == 0){
            execl("/bin/sh","sh","/home/parth/chad.sh",NULL);
        }
        if(id2 !=0){
            waitpid(id2,NULL,0);
            clock_gettime(CLOCK_REALTIME, &end1);
            long long int val = end1.tv_sec - ini2.tv_sec ;
            printf("%d",val);
            // // 
            sleep(3);
            execl("/bin/sh","sh","/home/parth/chad.sh",NULL);

        }
    }
    if(id2 ==0){
        waitpid(id1, NULL, 0);
        clock_gettime(CLOCK_REALTIME, &end1);
        long long int val = end1.tv_sec - ini2.tv_sec ;
        printf("%d",val);
        sleep(1);
        execl("/bin/sh","sh","/home/parth/chad.sh",NULL);
    }
    if(id1 !=0 && id2!=0){
            waitpid(id2,NULL,0);
            clock_gettime(CLOCK_REALTIME, &end1);
            long long int val = end1.tv_sec - ini2.tv_sec ;
            printf("%lld",val);
            sleep(4);
            execl("/bin/sh","sh","/home/parth/chad.sh",NULL);
    }
}