#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
      pid_t pid;
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){   //父进程 
	    int ret;
	    if((pid = fork()) < 0){
	    
	    }else if(pid == 0){ //子进程2
		 sleep(1); 
		  exit(10);
	    }
	    printf("parent:pid = %d\n",getpid());
	    printf("parent:ppid = %d\n",getppid());
	    wait(&ret);  //等待子进程结束，给子进程收尸
	    printf("this is parent!\n");
	    printf("ret: %d\n", WEXITSTATUS(ret));
	    exit(0);
      }else{  //子进程1
	    printf("child:pid = %d\n",getpid());
	    printf("child:ppid = %d\n",getppid());
	    exit(20);	    
      } 

}
