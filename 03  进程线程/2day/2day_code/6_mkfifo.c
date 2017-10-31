#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc,char **argv)
{

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <file>\n",argv[1]);
	    exit(1);
      }

      if(mkfifo(argv[1],0666) < 0){
	    perror("mkfifo");
	    exit(0);
      }
      return 0;
}
