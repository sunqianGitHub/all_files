#include <stdio.h>


int main(void)
{
      char str[] = "100 23.56 nihao";
      int a;
      float f;
      char buf[8];
      //把字符串拆解成不同类型
      sscanf(str,"%d%f%s",&a,&f,buf);
      printf("a=%d\n",a);
      printf("f=%f\n",f);
      printf("buf=%s\n",buf);


      return 0;

}

