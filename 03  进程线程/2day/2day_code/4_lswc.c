#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
      int fd[2];
      pid_t pid;

      //创建无名管道
      if(pipe(fd) < 0){
	    perror("pipe");
	    exit(1);
      }

      if((pid = fork()) < 0 ){
	    perror("fork");
	    exit(1);
      }else if(pid == 0){  //子进程:执行ls，并将结果写入管道
	    close(fd[0]);
	    dup2(fd[1],STDOUT_FILENO);
	    execlp("ls","ls",NULL);
      }else{  //父进程:从管道获取数据，并通过wc统计
	    close(fd[1]); 
	    dup2(fd[0],STDIN_FILENO);
	    execlp("wc","wc","-w",NULL);
      }
      return 0;
}
