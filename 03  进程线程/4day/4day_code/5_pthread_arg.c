#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct A{
      int a;
      float b;
};

void * fun(void * pa)
{
      //printf("a = %f\n",*(float*)pa);
      //printf("%s\n",(char*)pa);
      //struct A *pst = (struct A*)pa;
      //printf("%d\t%f\n",pst->a,pst->b);
      printf("%d\t%f\n",((struct A*)pa)->a,((struct A*)pa)->b);
      
      return (void*)0;
}

int main(void)
{
      pthread_t tid;
      //float a = 12.34;
      char buf[] = "hello world";
      struct A st = {100,3.5};

      if(pthread_create(&tid,NULL,fun,&st) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      sleep(1);
      return 0;
}
