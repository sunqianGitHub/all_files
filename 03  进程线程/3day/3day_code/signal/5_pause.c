#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
int main(int argc,char **argv)
{

      int i;
      alarm(7);
      pause();
      return 0;
}
