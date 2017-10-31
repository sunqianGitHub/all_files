#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


int main(int argc,char *argv[])
{
      FILE *read_fp,*write_fp;
      char buf[SIZE];

      if(argc != 3)
      {
	    printf("usage: %s <src_filename> <des_filename>\n",argv[0]);
	    exit(1);
      }

      read_fp = fopen(argv[1],"r");
      if(NULL == read_fp)
      {
	    perror("fopen failed");
	    exit(1);
      }

      write_fp = fopen(argv[2],"w");
      if(NULL == write_fp)
      {
	    perror("fopen failed");
	    exit(1);
      }

      while(fgets(buf,10,read_fp) != NULL)
      {
	    fputs(buf,stdout);    
	    fputs(buf,write_fp);    
//      printf("%s",buf);
      }
      return 0;
}
