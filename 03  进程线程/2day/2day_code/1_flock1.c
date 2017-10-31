#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/file.h>

//#define LOCK

int main(int argc, char **argv)
{
      int fd;
      char buf[BUFSIZ];
      int i;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <file>\n",argv[1]);
	    exit(1);
      }

      if((fd = open(argv[1],O_WRONLY|O_CREAT,0666)) < 0){
	    perror("open");
	    exit(1);
      }

      strcpy(buf,"hello world\n");
#ifdef LOCK
      flock(fd,LOCK_EX);
#endif
      for(i = 0; i < 10; i++){
	  //  fgets(buf,BUFSIZ,stdin);
	    write(fd,buf,strlen(buf));
	    printf("%s",buf);
	    sleep(1);
      }
#ifdef LOCK
      flock(fd,LOCK_UN);
#endif

      close(fd);

      return 0;
}

