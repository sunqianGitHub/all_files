#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
      FILE *fp;
      int i;
      char ch;

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

      //获取文件指针当前位置 
      printf("first:%ld\n",ftell(fp));
      //修改文件偏移位置
      fseek(fp,2,SEEK_SET);
      printf("second:%ld\n",ftell(fp));
      fseek(fp,3,SEEK_CUR);
      printf("third:%ld\n",ftell(fp));
      fseek(fp,-4,SEEK_END);
      printf("forth:%ld\n",ftell(fp));
      printf("%c\n",fgetc(fp));
      return 0;
}
