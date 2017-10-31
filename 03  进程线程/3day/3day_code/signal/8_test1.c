#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>

void fun(int signo)
{
      FILE *fp;
      time_t tm;

      fp = fopen("1.txt","a+");
      if(fp == NULL){
	    perror("fopen");
	    exit(1);
      }
      time(&tm);
      fputs(ctime(&tm),fp);
      fflush(fp);
      printf("向文件中写入了一条时间信息\n");

      fclose(fp);
}

int main(int argc,char **argv)
{
      time_t tm;
      int fd;
      pid_t pid;

      signal(SIGUSR1,fun);
      
      fd = open("fifo",O_RDWR);
      if(fd < 0){
	    perror("open");
	    exit(1);
      }

      pid = getpid();
      write(fd,&pid,4);
      

      while(1){
	    time(&tm);
	    printf("%s",ctime(&tm));
	    sleep(1);
      }     
      return 0;
}
