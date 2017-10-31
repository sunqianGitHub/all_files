#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * fun(void * n)
{
      printf("我是子线程!\n");
      return (void*)0;
}

int main(void)
{
      pthread_t tid;
      
      if(pthread_create(&tid,NULL,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      printf("tid = %lu\n",tid);

      sleep(1);
      return 0;
}
