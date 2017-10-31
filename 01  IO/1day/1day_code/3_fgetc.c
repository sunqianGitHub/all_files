#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{
      FILE *fp;

      if(argc != 2)
      {
	    printf("usage: %s <filename> ?\n",argv[0]);
	    exit(1);
      }

      fp = fopen(argv[1],"r");
      if(fp == NULL)
      {
	    perror("fopen failed");
	    exit(1);
      }

      char ch;
      //EOF 表示文件结束或出错
      while((ch=fgetc(fp)) != EOF)
      {
//	    printf("%c",ch);
	    //stdout 标准输出
	    fputc(ch,stdout);
      }


      return 0;
}
