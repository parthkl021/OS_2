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

FILE *p1, *p2, *p3;
// int val1;
// int val2;
// int val3;

int pri1;
int pri2;
int pri3;

void countA()
{
    long long int count;
    for (long long int i = 0; i < 4294967296; i++)
    {
        count = count + 1;
    }
}
void countB()
{
    long long int count;
    for (long long int i = 0; i < 4294967296; i++)
    {
        count = count + 1;
    }
}
void countC()
{
    long long int count;

    for (long long int i = 0; i < 4294967296; i++)
    {
        count = count + 1;
    }
}
void *ThrA()
{
    struct sched_param ft1;
    ft1.sched_priority = pri1;
    // int k = setpriority(PRIO_PROCESS,0,-20);
    // printf("%d\n",k);
    int a2 = pthread_setschedparam(t, SCHED_OTHER, &ft1);
    struct timespec ini, end;
    clock_gettime(CLOCK_REALTIME, &ini);
    countA();
    clock_gettime(CLOCK_REALTIME, &end);
    double val = (end.tv_sec - ini.tv_sec) + (end.tv_nsec - ini.tv_nsec) / 1000000000.0;
    printf("For SCHED_OTHER part: ");
    printf("%lf", val);
    char wr[50];
    sprintf(wr, "%lf\n%d\n", val, pri1);

    fputs(wr, p1);
    printf("\n");
}
void *ThrB()
{
    struct sched_param ft2;
    ft2.sched_priority = pri2;
    int a = pthread_setschedparam(t2, SCHED_RR, &ft2);
    struct timespec ini1, end1;
    clock_gettime(CLOCK_REALTIME, &ini1);
    countB();
    clock_gettime(CLOCK_REALTIME, &end1);
    double val1 = end1.tv_sec - ini1.tv_sec + (end1.tv_nsec - ini1.tv_nsec) / 1000000000.0;
    printf("For SCHED_RR part: ");
    printf("%lf", val1);
    char wr1[50];
    sprintf(wr1, "%lf\n%d\n", val1, pri2);

    fputs(wr1, p2);
    printf("\n");
}
void *ThrC()
{
    struct sched_param ft3;
    ft3.sched_priority = pri3;
    int a3 = pthread_setschedparam(t3, SCHED_FIFO, &ft3);
    struct timespec ini2, end2;
    clock_gettime(CLOCK_REALTIME, &ini2);
    countC();
    clock_gettime(CLOCK_REALTIME, &end2);
    double val2 = end2.tv_sec - ini2.tv_sec + (end2.tv_nsec - ini2.tv_nsec) / 1000000000.0;
    printf("For SCHED_FIFO part: ");
    printf("%lf", val2);
    char wr2[50];
    sprintf(wr2, "%lf\n%d\n", val2, pri3);
    fputs(wr2, p3);
    printf("\n");
}

int main(int argc, char *argv[])
{

    p1 = fopen("other.txt", "a");
    p2 = fopen("rr.txt", "a");
    p3 = fopen("fifo.txt", "a");
    pri1 = atoi(argv[1]);
    pri2 = atoi(argv[2]);
    pri3 = atoi(argv[3]);
    pthread_create(&t, NULL, &ThrA, NULL);
    pthread_create(&t2, NULL, &ThrB, NULL);
    pthread_create(&t3, NULL, &ThrC, NULL);

    pthread_join(t, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    fclose(p1);
    fclose(p2);
    fclose(p3);
}