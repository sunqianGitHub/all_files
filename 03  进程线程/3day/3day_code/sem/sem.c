#include "sem.h"


//初始化信号量
void sem_init(int sem_id,int value)
{
      union semun sem;
      sem.val = value;
      if(semctl(sem_id,0,SETVAL,sem) < 0){
	    perror("semop");
	    exit(1);
      }
}
//p操作
void sem_p(int sem_id,int num)
{
      struct sembuf sp = {num,-1,0};
      if(semop(sem_id,&sp,1) < 0){
	    perror("semop");
	    exit(1);
      }
}
//v操作
void sem_v(int sem_id,int num)
{
      struct sembuf sp = {num,1,0};
      if(semop(sem_id,&sp,1) < 0){
	    perror("semop");
	    exit(1);
      }
}
