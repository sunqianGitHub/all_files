#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
      FILE *read_fp;
      FILE *write_fp;

      if(argc != 3)
      {
	    printf("usage: %s <src_file> <des_file>\n",argv[0]);
	    exit(1);
      }

      read_fp = fopen(argv[1],"r");
      if(NULL == read_fp)
      {
	    perror("fopen failed");
	    exit(1);
      }

      write_fp = fopen(argv[2],"w");
      if(write_fp == NULL)
      {
	    perror("fopen failed");
	    exit(1);      
      }
      char ch;

      while((ch=fgetc(read_fp)) != EOF)	  
      {
	    fputc(ch,stdout);
	    fputc(ch,write_fp);  
      }
     

      return 0;
}
