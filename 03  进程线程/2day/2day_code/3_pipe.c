#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
      char buf[BUFSIZ];
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
      }else if(pid == 0){  //子进程:从键盘获得数据，写入管道
	    while(1){
		  bzero(buf,BUFSIZ);
		  fgets(buf,BUFSIZ,stdin);
		  close(fd[0]);  //关闭读端
		  write(fd[1],buf,strlen(buf));
		  if(strncmp(buf,"quit",4) == 0)
			break;
	    }	    
	    exit(0);
      }else{  //父进程:从管道读出数据，并打印到终端
	   while(1){ 
		 close(fd[1]);
		  bzero(buf,BUFSIZ);
		  read(fd[0],buf,BUFSIZ);
		  if(strncmp(buf,"quit",4) == 0)
			break;
		  printf("从管道中读%d个字符:%s",strlen(buf),buf);
	   }
	   exit(0);
      }
      return 0;
}
