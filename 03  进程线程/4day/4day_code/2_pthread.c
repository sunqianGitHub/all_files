#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void * fun(void * n)
{
      int i;
      for( i = 0; i < 5; i++){
	    printf("this is fun!\n");
	    sleep(1);
      }

      return (void*)0;
}

int main(void)
{
      int i;
      pthread_t tid;
      
      if(pthread_create(&tid,NULL,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      for(i = 0; i < 5; i++){
	    printf("this is main!\n");
	    sleep(1);
      }
      return 0;
}
