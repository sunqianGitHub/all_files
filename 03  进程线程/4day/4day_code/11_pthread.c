#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define LOCK
int vl1,vl2;

pthread_mutex_t m;

void * thread_fun(void * pa)
{
      while(1){
#ifdef LOCK
	    pthread_mutex_lock(&m);
#endif
	    if(vl1 != vl2)
		  printf("vl1=%d,vl2=%d\n",vl1,vl2);
#ifdef LOCK
	    pthread_mutex_unlock(&m);
#endif
      }
      pthread_exit(0);
}

int main(void)
{
      pthread_t tid;
      int i;
      
      //初始化互斥锁
      pthread_mutex_init(&m,NULL);

      //创建线程
      if(pthread_create(&tid,NULL,thread_fun,NULL) != 0){
	    perror("pthread_create");
	    exit(1);
      }
      
      for(i = 0; ;i++){
#ifdef LOCK
	    pthread_mutex_lock(&m);
#endif
	    vl1 = i+1;
	    vl2 = i+1;
#ifdef LOCK
	    pthread_mutex_unlock(&m);
#endif
      }

      //等待子线程结束，否则阻塞当前线程
      if(pthread_join(tid,NULL) != 0){
	    perror("pthread_join");
	    exit(1);
      }
      return 0;
}
