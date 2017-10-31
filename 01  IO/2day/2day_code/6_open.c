#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int main(int argc,char *argv[])
{
      int fd;

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

//      fd = open(argv[1],O_RDONLY,0664);
      fd = open(argv[1],O_WRONLY|O_CREAT|O_EXCL,0664);
      if(fd<0)
      {
	    perror("open failed");
	    exit(1);
      }


      return 0;
}

