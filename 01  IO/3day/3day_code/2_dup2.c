#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
      char buf[BUFSIZ];
      int fd;

      if(argc != 2)
      {
	    printf("usage : %s <filename>\n",argv[0]);
	    exit(1);
      }

      fd = open(argv[1],O_WRONLY|O_CREAT,0664);
      if(fd<0)
      {
	    perror("open failed");
	    exit(1);
      }

      while(1)
      {
	    fgets(buf,BUFSIZ,stdin);
	    //重定向文件描述符
	 //   dup2(STDOUT_FILENO,fd);
	    //把fd赋值/复制给STDOUT_FILENO
	    dup2(fd,STDOUT_FILENO);
	    write(STDOUT_FILENO,buf,strlen(buf));
      }




      return 0;
}
