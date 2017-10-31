#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>


#define SIZE 10

int main(int argc,char *argv[])
{
      int fd;
      int ret;
      char buf[SIZE];

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      fd = open(argv[1],O_RDONLY);
      if(fd < 0)
      {
	    perror("open failed");
	    exit(1);
      }
#if 0
      ret = read(fd,buf,BUFSIZ);
      if(ret < 0)
      {
	    perror("read failed");
	    exit(1);
      }
      else if(ret == 0)
	    exit(1);
      else
      {
	    printf("%s\n",buf);
      }
#endif
      while(1)
      {
	    ret = read(fd,buf,SIZE);
	    if(ret < 0)
	    {
		  perror("read failed");
		  exit(1);
	    }
	    else if(ret == 0)
		  exit(1);
	    else
	    {
		  printf("%s",buf);
	    }
      }

      return 0;
}
