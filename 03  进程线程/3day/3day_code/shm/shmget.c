#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>


#define SHMSIZE  1024

int main(void)
{
     int shm_id;
     key_t key;
#if 0
      if((shm_id = shmget(IPC_PRIVATE,SHMSIZE,IPC_CREAT|0666)) < 0){
	    perror("shmget");
	    exit(1);
      }
#else
      if((key = ftok("/",0xa)) < 0){
	    perror("ftok");
	    exit(1);
      }
      if((shm_id = shmget(key,SHMSIZE,IPC_CREAT|0666)) < 0){
	    perror("shmget");
	    exit(1);
      }
#endif
      return 0;
}
