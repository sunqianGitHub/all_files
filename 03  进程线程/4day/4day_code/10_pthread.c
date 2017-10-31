#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

int arr[10];

sem_t sem1,sem2;  //定义两个信号量

//从键盘获得10个整数
void * thread_fun1(void * arg)
{
      int i;
      printf("请输入10个整数:");
      for(i = 0;i < 10; i++)
	    scanf("%d",arr+i);
      sem_post(&sem1);  //v操作
      pthread_exit(0);
}
//对10个整数排序
void * thread_fun2(void * arg)
{
      int i,j,flag;

      sem_wait(&sem1);  //p操作
      for(i = 0; i < 9; i++){
	    flag = 1;
	    for(j = 0;j < 9-i; j++)
		  if(arr[j] > arr[j+1]){
			arr[j] += arr[j+1];
			arr[j+1] = arr[j] - arr[j+1];	
			arr[j] = arr[j] - arr[j+1];
			flag = 0;
		  }
	    if(flag)
		  break;
      }
      sem_post(&sem2);  //v操作
      pthread_exit(0);
}
//将排序之后的10个整数写入文件中
void * thread_fun3(void * arg)
{
      FILE * fp = NULL;
      
      sem_wait(&sem2);  //p操作

      if((fp = fopen("1.txt","a+")) == NULL){
	    perror("fopen");
	    exit(1);
      }

      int i;
      char buf[100];
      bzero(buf,100);

      for(i = 0; i < 10; i++)
	    sprintf(buf+strlen(buf),"%d\t",arr[i]);
      fputs(buf,fp);
      fflush(fp);
      if(fp != NULL)
	    fclose(fp);

      pthread_exit(0);
}

int main(void)
{
      int i;
      pthread_t tid[3];
      void *(*thread[3])(void*) = {thread_fun1,thread_fun2,thread_fun3};

      //初始化信号量
      sem_init(&sem1,0,0);
      sem_init(&sem2,0,0);
      //创建线程
      for(i = 0; i < 3; i++)
	    if(pthread_create(tid+i,NULL,thread[i],NULL) != 0){
		  perror("pthread_create");
		  exit(1);
	    }

      //等待子线程结束，否则阻塞当前线程
      for(i = 0; i < 3; i++)
	    if(pthread_join(tid[i],NULL) != 0){
		  perror("pthread_join");
		  exit(1);
	    }
      return 0;
}
