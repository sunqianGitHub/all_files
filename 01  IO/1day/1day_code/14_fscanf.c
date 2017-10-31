#include <stdio.h>
#include <stdlib.h>


int main(void)
{
      FILE *fp;
      int a;
      float f;

      fp = fopen("1.txt","r");
      if(NULL == fp)
      {
	    perror("fopen failed");
	    exit(1);
      }
      //从fp指向的文件向变量a f输入数据
      fscanf(fp,"%d%f",&a,&f);
      printf("a=%d, f=%f\n",a,f);


      return 0;
}
