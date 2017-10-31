#include <stdio.h>
#include <unistd.h>

int main(void)
{
      char filename[1024];

      //创建一个临时文件
      tmpnam(filename);
      fopen(filename,"w");
      printf("%s\n",filename);
      sleep(5);
      unlink(filename);

      return 0;
}
