#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <stdio.h>
#include <sched.h>
#include <time.h>
#include <sys/resource.h>     
#include <stdlib.h>
pthread_t t;
pthread_t t2;
pthread_t t3;
int index = 0;
FILE *p1, *p2, *p3;
void countA(){
        // clock_gettime(CLOCK_REALTIME, &ini);
        long long int count;
        // printf("hello1\n");
        for (long long int i = 0; i < 4294967296; i++){
        count = count + 1;
        }
        // printf("hello 1 end\n");
    }
void countB(){
        long long int count;
        // printf("hello2\n");
        for (long long int i = 0; i < 4294967296; i++){
        count = count + 1;
        }
        // printf("hello 2 end\n");
    }
void countC(){
        long long int count;
        // printf("hello3\n");
        for (long long int i = 0; i < 4294967296; i++){
        count = count + 1;
        }
        // printf("hello 3 end\n");
    }
void *ThrA(){
    struct sched_param ft1;
    ft1.sched_priority = index;
    int k = setpriority(PRIO_PROCESS,0,-20);
    printf("%d\n",k);
    int a2 = pthread_setschedparam(t,SCHED_OTHER,&ft1);
    struct timespec ini, end;
    
    clock_gettime(CLOCK_REALTIME, &ini);
    
    countA();
    
    clock_gettime(CLOCK_REALTIME, &end);
    
    double val = (end.tv_sec - ini.tv_sec)+(end.tv_nsec - ini.tv_nsec)/1000000000.0;
    p1 = fopen("other.txt", "w+");
    fputs(sprintf(val), p1);
    fclose(p1);

    printf("For SCHED_OTHER part: ");
    printf("%lf",val);
    printf("\n");
}
void *ThrB(){
    struct sched_param ft2 ;
    ft2.sched_priority = index;

    int a = pthread_setschedparam(t2,SCHED_RR,&ft2);
    struct timespec ini1, end1;
    clock_gettime(CLOCK_REALTIME, &ini1);
    
    countB();
    
    clock_gettime(CLOCK_REALTIME, &end1);
    double val1 = end1.tv_sec - ini1.tv_sec + (end1.tv_nsec - ini1.tv_nsec)/1000000000.0;
    printf("For SCHED_RR part: ");
    printf("%lf",val1);
    printf("\n");
}
void *ThrC(){
    // struct sched_param *ft3 = malloc(sizeof(struct sched_param));
    struct sched_param ft3;
    ft3.sched_priority = index;
    // ft3->sched_priority = 1;
    int a3 = pthread_setschedparam(t3,SCHED_FIFO,&ft3);
    struct timespec ini2, end2;
    clock_gettime(CLOCK_REALTIME, &ini2);

    countC();
    
    clock_gettime(CLOCK_REALTIME, &end2);
    double val2 = end2.tv_sec - ini2.tv_sec + (end2.tv_nsec - ini2.tv_nsec)/1000000000.0;
    printf("For SCHED_FIFO part: ");
    printf("%lf",val2);
    printf("\n");
}
int main (){
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&t,NULL,&ThrA,NULL);
        pthread_create(&t2,NULL,&ThrB,NULL);
        pthread_create(&t3,NULL,&ThrC,NULL);
        index = index + 17;
        pthread_join(t, NULL);
        pthread_join(t2,NULL);
        pthread_join(t3,NULL);
    }
    
    
}
