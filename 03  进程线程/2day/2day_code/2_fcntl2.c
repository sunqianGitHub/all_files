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

      strcpy(buf,"afafgaflkafla\n");
#ifdef LOCK
      struct flock fl = {F_WRLCK,SEEK_SET,0,1024};
      fcntl(fd,F_SETLKW,&fl);
#endif
      for(i = 0; i < 10; i++){
	  //  fgets(buf,BUFSIZ,stdin);
	    write(fd,buf,strlen(buf));
	    printf("%s",buf);
	    sleep(1);
      }
#ifdef LOCK
      fl.l_type = F_UNLCK;
      fcntl(fd,F_SETLKW,&fl);
#endif

      close(fd);

      return 0;
}

