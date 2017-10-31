#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

pid_t pid;

void fun(int signo)
{
      printf("给%d发送信号!\n",pid);
      kill(pid,SIGUSR1);
}

int main(int argc,char **argv)
{
      int fd;
      signal(SIGINT,fun);
      printf("%d\n",getpid());
      fd = open("fifo",O_RDWR);
      if(fd < 0){
	    perror("open");
	    exit(1);
      }
      read(fd,&pid,4);
      while(1);
	    pause();	    
      return 0;
}
