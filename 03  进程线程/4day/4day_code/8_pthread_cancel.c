#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * fun(void * n)
{
      int i;
      for( i = 0; i < 10; i++){
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
      for(i = 0; i < 10; i++){
	    if(i == 5){
		  //结束子线程的执行
		  if(pthread_cancel(tid) != 0){
			perror("pthread_cancel");
			exit(1);
		  }
	    }
	    printf("this is main!\n");
	    sleep(1);
      }


      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      return 0;
}
