#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>



int main(void)
{
      pid_t pid;

      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid == 0){
	    while(1){
		  printf("pid:%d\n",getpid());
		  printf("hello world\n");
		  sleep(1);
	    }
      }else{
	    if((pid = fork()) < 0){
		  perror("fork");
		  exit(1);
	    }else if(pid == 0){
		  
		  sleep(10);
		  kill(-1,SIGKILL);
	    
	    } 
	    while(1){
		  printf("pid:%d\n",getpid());
		  printf("farsight\n");
		  sleep(1);
	    }
	    
      }
      
#if 0      
      n = 8 / 0;
      printf("n = %d\n",n);
#endif
      return 0;
}
