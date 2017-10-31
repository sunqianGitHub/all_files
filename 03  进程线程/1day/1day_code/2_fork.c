#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
#if 0
      printf("farsight\n");
      fork();
      printf("hello world\n");
#else
      pid_t pid;
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){   //父进程 
	    //sleep(1);
	    printf("parent:pid = %d\n",getpid());
	    printf("parent:ppid = %d\n",getppid());
      }else{  //子进程
	    printf("child:pid = %d\n",getpid());
	    printf("child:ppid = %d\n",getppid());
	    
      }
      printf("SDSDFSFSDF\n");
#endif
}
