#include "shm.h"


int main(int argc,char **argv)
{
#if  0
      //获取共享内存属性方法
      struct shmid_ds shm;
      if(shmctl(atoi(argv[1]),IPC_STAT,&shm) < 0){
	    perror("shmctl");
	    exit(1);
      }

      printf("size:%d\n",shm.shm_segsz);
      printf("%s",ctime(&shm.shm_atime));   
      printf("%s",ctime(&shm.shm_dtime));   
      printf("%s",ctime(&shm.shm_ctime));   
#else
      if(shmctl(atoi(argv[1]),IPC_RMID,NULL) < 0){
	    perror("shmctl");
	    exit(1);
      }
#endif
      return 0;
}
