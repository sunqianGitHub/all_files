#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char **argv)
{
      chdir("/");
      if(open(argv[1],O_RDWR|O_CREAT,0666) < 0){
	    perror("error");
	    exit(1);
      }
      return 0;
}
