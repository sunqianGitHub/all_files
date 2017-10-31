#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


#define SIZE 10

int main(int argc,char *argv[])
{
      FILE *read_fp,*write_fp;

      if(argc != 3)
      {
	    printf("usage: %s <src_filename> <des_filename>\n",argv[0]);
	    exit(1);
      }

      read_fp = fopen(argv[1],"r");
      if(read_fp == NULL)
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

      char buf[SIZE];
      while(!feof(read_fp) &&  !ferror(read_fp))
      {
      	    //清空数组
	     bzero(buf,SIZE);
	     fread(buf,sizeof(char),SIZE,read_fp);
//	     printf("%s",buf);
//	     fwrite(buf,sizeof(char),SIZE,write_fp);
	     //写入时写buf里面的实际大小
	     fwrite(buf,sizeof(char),strlen(buf),write_fp);
      }

      fclose(read_fp);
      fclose(write_fp);

      return 0;
}
