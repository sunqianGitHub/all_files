#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * fun(void * pa)
{
#if 0
      int i;
      for(i = 0; i < 5; i++){
	    printf("fun!\n");
	    sleep(1);
      } 
#endif
      //static int a = 10000;
      static char str[] = "hello world";
      return str;
}

int main(void)
{
      pthread_t tid;
      if(pthread_create(&tid,NULL,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
#if 0
      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
#else
      //int *pa;
      char *str;
      if(pthread_join(tid,(void**)&str) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      
      //printf("*pa = %d\n",*pa);
      printf("%s\n",str);
#endif
      return 0;
}
