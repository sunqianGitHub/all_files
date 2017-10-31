#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
      char buf[BUFSIZ] = "hello world\n";
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
      }else if(pid == 0){ 
	    //关闭管道的读段
	    close(fd[0]);
	    while(1){
		  write(fd[1],buf,strlen(buf));
		  printf("%s",buf);
		  sleep(1);
	    }
      }else{  
	    close(fd[0]);
	    while(1){
		  //read(fd[0],buf,BUFSIZ);
		  printf("%s",buf);
	    }

      }
      return 0;
}
