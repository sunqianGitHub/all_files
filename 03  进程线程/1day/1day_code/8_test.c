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
	    while(1){
		  printf("hello world\n");
		  sleep(1);
	    }
      }else{  //子进程

	    while(1){
		  printf("farsight\n");
		  sleep(1);
	    }
	    
      }
}
