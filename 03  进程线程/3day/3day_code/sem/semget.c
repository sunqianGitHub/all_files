#include "sem.h"


int main(void)
{
      int sem_id;
      key_t key;

      if((key = ftok("/",0xb)) < 0){
	    perror("ftok");
	    exit(1);
      }
      if((sem_id = semget(key,1,IPC_CREAT|0666)) < 0){
	    perror("semget");
	    exit(1);
      }
      return 0;
}
