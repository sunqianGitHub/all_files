#ifndef __SEM_H__
#define __SEM_H__


#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
      int              val;    /* Value for SETVAL */
      struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
      unsigned short  *array;  /* Array for GETALL, SETALL */
      struct seminfo  *__buf;  /* Buffer for IPC_INFO
				  (Linux-specific) */
};

extern void sem_init(int sem_id,int value);
extern void sem_p(int sem_id,int num);
extern void sem_v(int sem_id,int num);
#endif
