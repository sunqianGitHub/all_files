#include "shm.h"

int main(void)
{
      int shm_id;
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


      //1.将共享内存映射到当前进程的虚拟空间
      if((buf = (char*)shmat(shm_id,NULL,0)) < 0){
	    perror("shmat");
	    exit(1);
      }
      //2.从键盘获得数据，写入共享类型
      while(1){
	    fgets(buf,SHMSIZE,stdin);
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
