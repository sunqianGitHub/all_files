#include <stdio.h>

//把别的类型转换成字符串类型
int main(void)
{
      char str[10];

#if 1
      
      sprintf(str,"%d\t%f",100,23.56);
      printf("%s\n",str);
#else
      //防止溢出
      snprintf(str,10,"%d\t%f",100,23.56);
      printf("%s\n",str);
#endif

      return 0;
}
