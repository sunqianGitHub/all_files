#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char *argv[])
{
      int fd;

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      fd = open(argv[1],O_WRONLY|O_CREAT,0664);
      if(fd < 0)
      {
	    perror("open failed");
	    exit(1);
      }

      //1、设置偏移量
      lseek(fd,1024,SEEK_SET);
      //2、写入标记信息
      write(fd,"end",strlen("end"));
      lseek(fd,-1000,SEEK_END);
      write(fd,"wuma",strlen("wuma"));

      return 0;
}
