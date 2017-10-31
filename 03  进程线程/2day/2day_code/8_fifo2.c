#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc,char **argv)
{

      char buf[BUFSIZ];
      int fd;

      if(argc != 2){
	    fprintf(stderr,"Usage:%s <file>\n",argv[1]);
	    exit(1);
      }

      //打开有名管道
      if((fd = open(argv[1],O_RDWR)) < 0){
	    perror("open");
	    exit(1);
      }
      while(1){ 
	    bzero(buf,BUFSIZ);
	    read(fd,buf,BUFSIZ);
	    if(strncmp(buf,"quit",4) == 0)
		  break;
	    printf("从管道中读%d个字符:%s",strlen(buf),buf);
      }
      return 0;
}
