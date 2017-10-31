#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{
      pid_t pid;
      //创建子进程
      if((pid = vfork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0){   //父进程 
	    while(1){
		  sleep(1);
		  printf("hello world\n");
	    }
	    exit(0);
      }else{  //子进程:加载ls命令并执行
	    //execl("/bin/ls","ls","-l",NULL);
	    //char *arg[] = {"ls","-l",NULL};
	    //execv("/bin/ls",arg);
	    execlp("ls","ls","-l",NULL);
	    exit(0);
      }
}
