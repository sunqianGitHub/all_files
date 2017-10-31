#include <stdio.h>
#include <stdlib.h>


#if 0
int main(void)
{
      //向标准输出写数据
      fprintf(stdout,"goodbay yesterday\n");

      while(1);

      return 0;
}
#endif


int main(int argc,char *argv[])
{
      FILE *fp;

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      fp = fopen(argv[1],"w");
      if(NULL == fp)
      {
	    perror("fopen failed");
	    exit(1);
      }

//      fprintf(fp,"helloworld");
      //向文件写入数据
      fprintf(fp,"%d\t%f",100,23.56);

      return 0;
}
