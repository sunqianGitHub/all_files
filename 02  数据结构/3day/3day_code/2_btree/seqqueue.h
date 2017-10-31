#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

#define SIZE 8
typedef btree_pnode datatype;

typedef struct seqqueue{
      datatype data[SIZE];
      int front,rear;
}seq_queue,*seq_pqueue;

extern void init_seqqueue(seq_pqueue *Q);
extern bool in_seqqueue(seq_pqueue q,datatype d);
extern bool out_seqqueue(seq_pqueue q,datatype *D);
extern bool isempty_seqqueue(seq_pqueue q);
extern bool isfull_seqqueue(seq_pqueue q);
//extern void show_seqqueue(seq_pqueue q);
#endif
