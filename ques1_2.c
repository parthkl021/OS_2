#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>

int main(){
    int id1;
    int id2;
    int id3;
    long long int val;
    long long int val1;
    long long int val2;
    struct timespec ini1, end1;
    clock_gettime(CLOCK_REALTIME, &ini1);
    
    struct timespec ini2, end2;
    clock_gettime(CLOCK_REALTIME, &ini2);
    
    struct timespec ini3, end3;
    clock_gettime(CLOCK_REALTIME, &ini3);
    

    id1 = fork();
    
    if(id1 ==0 ){
        execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
        return 0;
    }
    id2 = fork();
    if(id2 ==0 ){
       execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
       return 0;
    }
    id3 = fork();
    if(id3 ==0 ){
        execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
        return 0;
    }

    int k = waitpid(-1,NULL,0);
    while(k>0){
        if(id1 == k ){
            clock_gettime(CLOCK_REALTIME, &end1);
            val = end1.tv_sec - ini2.tv_sec ;
            
            }
        else if(id2 == k ){
            clock_gettime(CLOCK_REALTIME, &end2);
               val1 = end2.tv_sec - ini2.tv_sec ;
        }
        else if(id3 ==k ){
            clock_gettime(CLOCK_REALTIME, &end3);
            val2 = end3.tv_sec - ini3.tv_sec ;
        }
        else{
        }
        k = waitpid(-1,NULL,0);
    }
    printf("%lld\n",val);
    printf("%lld\n",val1);
    printf("%lld\n",val2);
    }  
