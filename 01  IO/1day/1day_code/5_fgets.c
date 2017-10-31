#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


int main(int argc,char *argv[])
{
      FILE *fp;
      char buf[SIZE];

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      fp = fopen(argv[1],"r");
      if(NULL == fp)
      {
	    perror("fopen failed");
	    exit(1);
      }

      while(fgets(buf,10,fp) != NULL)
      {
	    fputs(buf,stdout);    
//      printf("%s",buf);
      }
      return 0;
}
