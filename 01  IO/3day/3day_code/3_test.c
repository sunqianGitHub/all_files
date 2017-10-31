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
      umask(0022);
      fd = open(argv[1],O_WRONLY|O_CREAT,0666);
      if(fd<0)
      {
	    perror("open failed");
	    exit(1);
      }


      return 0;
}
