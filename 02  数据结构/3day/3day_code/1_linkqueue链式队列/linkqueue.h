#ifndef __SEQQUEUE_H__
#define __SEQQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8
typedef int datatype;

typedef struct queuenode{
      datatype data;
      struct queuenode *next;
}queue_node,*queue_pnode;

typedef struct linkqueue{
      queue_pnode front,rear;
}link_queue,*link_pqueue;

extern void init_linkqueue(link_pqueue *Q);
extern bool in_linkqueue(link_pqueue q,datatype d);
extern bool out_linkqueue(link_pqueue q,datatype *D);
extern bool isempty_linkqueue(link_pqueue q);
extern void show_linkqueue(link_pqueue q);
#endif
