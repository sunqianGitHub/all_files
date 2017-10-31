#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
      int read_fd,write_fd;
      int ret;
      char buf[BUFSIZ];

      if(argc != 3)
      {
	    printf("usage: %s <src_file> <des_file>\n",argv[0]);
	    exit(1);
      }

      read_fd = open(argv[1],O_RDONLY);
      if(read_fd<0)
      {
	    fprintf(stderr,"open failed");
	    exit(1);
      }

      write_fd = open(argv[2],O_WRONLY|O_CREAT,0664);
      if(write_fd<0)
      {
	    fprintf(stderr,"open failed");
	    exit(1);
      }

      while(1)
      {
	    bzero(buf,BUFSIZ);
	    if(( ret= read(read_fd,buf,BUFSIZ))<0)
	    {

		  fprintf(stderr,"read failed");
		  exit(1);
	    }
	    else if(ret == 0)
	    {
		  exit(1);
	    }
	    else
	    {
		  //向文件描述符中写数据
		  write(write_fd,buf,strlen(buf));
		  write(STDOUT_FILENO,buf,strlen(buf));
	    }
      }

      
      if(close(read_fd)<0)
      {
	    perror("close failed");
	    exit(1);
      }

      if(close(write_fd)<0)
      {
	    perror("close failed");
	    exit(1);
      }

      return 0;
}
