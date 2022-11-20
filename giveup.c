#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>
int main(){
    struct timespec ini1, end1;
    clock_gettime(CLOCK_REALTIME, &ini1);
    int id1 = fork();
    struct timespec ini2, end2;
    clock_gettime(CLOCK_REALTIME, &ini2);
    int id2 = fork();
    struct timespec ini3, end3;
    clock_gettime(CLOCK_REALTIME, &ini3);
    int id3 = fork();

    if(id1 != 0 & id2 != 0 && id3 ==0){
        execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
    }
    if(id2 != 0 & id3 != 0 && id1 ==0){
        execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
    }
    if(id3 != 0 & id1 != 0 && id2 ==0){
        execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
    }
    else{
    }

    while(waitpid(id1,NULL,WNOHANG) != 0 || waitpid(id1,NULL,WNOHANG) != 0 || waitpid(id1,NULL,WNOHANG) != 0){
        if(id1 != 0 & id2 != 0 && id3 ==0){
        clock_gettime(CLOCK_REALTIME, &end1);
        long long int val = end1.tv_sec - ini1.tv_sec ;
        if(val <1){
        }
        else{
            printf("%lld\n",val); 
        }
    }
    if(id2 != 0 & id3 != 0 && id1 ==0){
        clock_gettime(CLOCK_REALTIME, &end2);
        long long int val1 = end2.tv_sec - ini2.tv_sec ;
        if(val1 <1){
        }
        else{
            printf("%lld\n",val1);
        }
    }
    if(id3 != 0 & id1 != 0 && id2 ==0){
       clock_gettime(CLOCK_REALTIME, &end3);
        long long int val2 = end3.tv_sec - ini3.tv_sec ;
        if(val2 <1){
        }
        else{
            printf("%lld\n",val2);
        } 
    }  
    }
    
}