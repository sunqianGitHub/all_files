#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(void)
{
      mkfifo("fifo",0666);
      return 0;
}
