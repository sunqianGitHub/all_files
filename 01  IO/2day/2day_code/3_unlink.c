#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[])
{

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      //删除一个文件,通过argv[1]
      unlink(argv[1]);


      return 0;
}
