#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void * thread_fun(void * pa)
{
      int i;
      for(i = 0; i < 5; i++){
	    printf("i = %d\n",i);
	    sleep(1);
      }
      pthread_exit(0);
}

int main(void)
{
      pthread_t tid;
      pthread_attr_t attr; //定义线程属性

      pthread_attr_init(&attr);  //初始化属性
      pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED); //设置线程分离属性
      //创建线程
      if(pthread_create(&tid,&attr,thread_fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
#if 0
      //等待子线程结束，否则阻塞当前线程
      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
#endif
      printf("子线程已结束!\n");
      //return 0;
      pthread_exit(0);
}
