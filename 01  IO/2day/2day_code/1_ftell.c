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

      for(i=0;i<3;i++)
      {

	    ch = fgetc(fp);
	    printf("%c\t",ch);
      }
      printf("\n");
      printf("second:%ld\n",ftell(fp));

      for(i=0;i<5;i++)
      {

	    ch = fgetc(fp);
	    printf("%c\t",ch);
      }
      printf("\n");
      printf("third:%ld\n",ftell(fp));

      return 0;
}
