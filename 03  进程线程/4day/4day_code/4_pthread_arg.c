#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * fun(void * pa)
{
      //printf("a = %d\n",(int)pa);
      printf("a = %d\n",*(int*)pa);
      return (void*)0;
}

int main(void)
{
      pthread_t tid;
      int a = 100;

      //if(pthread_create(&tid,NULL,fun,(void*)a) != 0){
      if(pthread_create(&tid,NULL,fun,&a) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      a = 124;
      sleep(1);
      return 0;
}
