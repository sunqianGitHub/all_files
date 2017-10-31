#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

void fun(int signo)
{
      int i;
      for(i = 0;i  < 5; i++){
	    printf("该起床了....\n");
	    sleep(1);
      }
}

int main(int argc,char **argv)
{

      int i;
      //signal(SIGALRM,SIG_IGN);
      signal(SIGALRM,fun);
      alarm(7);
      for(i = 0; i < 10; i++){
	    printf("睡觉中 %d ....\n",i+1);
	    sleep(1);
      }
      return 0;
}
