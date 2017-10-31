#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
void fun(int signo)
{
}

int main(int argc,char **argv)
{
      pid_t pid;
      int n;

      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){  //父进程
	    while(1){
		  scanf("%d",&n);
		  kill(pid,SIGUSR1);
	    }
      }else{  //子进程
	    signal(SIGUSR1,fun);
	    while(1){
		  printf("hello world\n");
		  pause();
	    }
      }
      return 0;
}
