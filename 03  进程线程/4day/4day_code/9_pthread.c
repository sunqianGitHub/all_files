#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//char buf[100];  //静态数据区
char *buf;

void fun(char *str)
{
      printf("%s\n",str);
}

void * thread_fun(void * pa)
{
      //堆空间
      buf = (char*)malloc(100);
      if(buf == NULL){
	    perror("malloc");
	    exit(1);
      }
      fgets(buf,100,stdin);
      fun("child_thread");
      pthread_exit(0);
}

int main(void)
{
      pthread_t tid;
      //创建线程
      if(pthread_create(&tid,NULL,thread_fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      //等待子线程结束，否则阻塞当前线程
      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      printf("%s\n",buf);
      fun("main_thread");
      return 0;
}
