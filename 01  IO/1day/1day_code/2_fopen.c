#include <stdio.h>
#include <stdlib.h>

//argc 参数个数
//argv[] 参数名
int main(int argc,char *argv[])
{
      FILE * fp;
      
      if(argc != 2)
      {
	    printf("usage: %s <filename> ?\n",argv[0]);
	    exit(1);
      }

      //打开文件
      fp = fopen(argv[1],"r");
      if(NULL == fp)
      {
	    perror("fopen failed");
	    exit(1);
      }


      return 0;
}
