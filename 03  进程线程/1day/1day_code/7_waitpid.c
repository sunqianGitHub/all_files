#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
      pid_t pid1,pid2;
      if((pid1 = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid1 > 0){   //父进程 
	    int ret;
	    if((pid2 = fork()) < 0){
		  perror("fork");
		  exit(1);
	    }else if(pid2 == 0){ //子进程2
		  sleep(2);
		  printf("child process2\n");
		 //sleep(1); 
		  exit(10);
	    }
	    waitpid(pid2,&ret,0);  //等待子进程结束，给子进程收尸
	    printf("this is parent!\n");
	    printf("ret: %d\n", WEXITSTATUS(ret));
	    exit(0);
      }else{  //子进程1
	    printf("child process1\n");
	    exit(20);	    
      } 

}
