#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * fun(void * n)
{
      printf("我是子线程!\n");
      //return (void*)0;
      static int a = 123;
      pthread_exit(&a);  //结束当前线程
}

int main(void)
{
      pthread_t tid;
      
      if(pthread_create(&tid,NULL,fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }

      int *pa;
      if(pthread_join(tid,(void**)&pa) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      printf("*pa = %d\n",*pa);
      return 0;
}
