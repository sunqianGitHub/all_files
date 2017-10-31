#include "shm.h"
#include "sem.h"

int main(void)
{
      int shm_id,sem_id;
      key_t key;

      char *buf;

      //获得key
      if((key = ftok("/",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }

      //创建或者获得共享内存的id
      if((shm_id = shmget(key,SHMSIZE,IPC_CREAT|0666)) < 0){
	    perror("shmget");
	    exit(1);
      }

      //创建或者获取信号灯
      if((sem_id = semget(key,1,IPC_CREAT|0666)) < 0){
	    perror("semget");
	    exit(1);
      }
      //初始化信号灯
      sem_init(sem_id,0);

      //1.将共享内存映射到当前进程的虚拟空间
      if((buf = (char*)shmat(shm_id,NULL,0)) < 0){
	    perror("shmat");
	    exit(1);
      }
      //2.从键盘获得数据，写入共享类型
      while(1){
	    fgets(buf,SHMSIZE,stdin);
	    //v操作:给信号量值加1，唤醒由于p操作阻塞的进程
	    sem_v(sem_id,0);
	    if(strncmp(buf,"quit",4) == 0)
		  break;
      }
      //3.解除映射
      if(shmdt(buf) < 0){
	    perror("shmdt");
	    exit(1);
      }
      return 0;
}
