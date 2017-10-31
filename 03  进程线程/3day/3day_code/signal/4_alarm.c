#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
int main(int argc,char **argv)
{

      int i;
      alarm(7);
      for(i = 0; i < 10; i++){
	    printf("sleep %d ....\n",i+1);
	    sleep(1);
      }
      return 0;
}
