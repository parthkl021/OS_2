#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/wait.h>
int main(){
    struct timespec ini1, end1;
    clock_gettime(CLOCK_REALTIME, &ini1);
    pid_t id1 = fork();
    struct timespec ini2, end2;
    clock_gettime(CLOCK_REALTIME, &ini2);
    pid_t id2 = fork();
    struct timespec ini3, end3;
    clock_gettime(CLOCK_REALTIME, &ini3);
    pid_t id3 = fork();
//	printf("%d %d %d\n",id1, id2, id3);	
//    if(id1 != 0 & id2 != 0 && id3 ==0){
  //      execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
   // }
   // if(id2 != 0 & id3 != 0 && id1 ==0){
     //   execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
  //  }
   // if(id3 != 0 & id1 != 0 && id2 ==0){
     //   execl("/bin/sh/","sh","/home/user/chad.sh",NULL);
   // }
   // else{
   // }
//	waitpid(id2,NULL,0);
//	waitpid(id3,NULL,0);
//	waitpid(id1,NULL,0);
//	while((id1 = waitpid(-1,NULL,WNOHANG))>0){
//	printf("fsds\n");
//	}
//	printf("%d %d %d \n",waitpid(id1,NULL,WNOHANG),waitpid(id2,NULL,WNOHANG),waitpid(id3,NULL,WNOHANG));
//	if(waitpid(id1,NULL,WNOHANG) == id1){
//	printf("huefhuj");
//}
 while(waitpid(id1,NULL,WNOHANG) != -1 && waitpid(id2,NULL,WNOHANG) != -1 && waitpid(id2,NULL,WNOHANG) != -1){
//	if(waitpid(id1,NULL,WNOHANG)== id1){
//		//printf("FEWF");
//		printf("%d",id1);
//	}
//	printf("%d\n\n",waitpid(id1,NULL,WNOHANG));
//        if(waitpid(id1,NULL,WNOHANG) == 0 ){
//        clock_gettime(CLOCK_REALTIME, &end1);
//       long long int val = end1.tv_sec - ini1.tv_sec ;
//      if(val <1){
//     }
//     else{
 //         printf("%lld\n",val); 
//       }
	while((id1 = waitpid(-1,NULL,WNOHANG))>0){
	printf("fssdc\n");
	}
    }
 //   if(waitpid(id2,NULL,WNOHANG) == 0 & waitpid(id3,NULL,WNOHANG) != 0 && waitpid(id1,NULL,WNOHANG) ==0){
   //     clock_gettime(CLOCK_REALTIME, &end2);
 //       long long int val1 = end2.tv_sec - ini2.tv_sec ;
       // if(val1 <1){
     //   }
   //     else{
      //      printf("%lld\n",val1);
    //    }
  //  }
  //  if(waitpid(id3,NULL,WNOHANG) == 0 & waitpid(id1,NULL,WNOHANG) == 0 && waitpid(id2,NULL,WNOHANG) ==0){
      // clock_gettime(CLOCK_REALTIME, &end3);
    //    long long int val2 = end3.tv_sec - ini3.tv_sec ;
  //      if(val2 <1){
//        }
    //    else{
      //      printf("%lld\n",val2);
  //      } 
//    }  
    }

