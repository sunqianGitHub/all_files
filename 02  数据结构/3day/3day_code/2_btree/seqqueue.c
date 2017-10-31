#include "seqqueue.h"

//初始化栈
void init_seqqueue(seq_pqueue *Q)
{
      *Q = (seq_pqueue)malloc(sizeof(seq_queue));
      if(NULL == *Q){
	    perror("malloc");
	    exit(1);
      }

      (*Q)->front = (*Q)->rear = SIZE-1;
}

//入队
bool in_seqqueue(seq_pqueue q,datatype d)
{
      if(isfull_seqqueue(q)){
	    printf("队列是满的!\n");
	    return false;
      }

      q->rear = (q->rear+1) % SIZE;
      q->data[q->rear] = d;
      return true;
}
//出队
bool   out_seqqueue(seq_pqueue q,datatype *D)
{
      if(isempty_seqqueue(q)){
	    printf("队列是空的!\n");
	    return false;
      }

      q->front = (q->front+1)%SIZE;
      *D = q->data[q->front];
      return true;
}

bool isempty_seqqueue(seq_pqueue q)
{
      if(q->rear == q->front)
	    return true;
      else
	    return false;
}
bool isfull_seqqueue(seq_pqueue q)
{
      if(q->front == (q->rear+1)%SIZE)
	    return true;
      else
	    return false;
}
#if 0
void show_seqqueue(seq_pqueue q)
{
      int i;
      for(i = (q->front+1)%SIZE;i != (q->rear+1)%SIZE;i = (i+1)%SIZE)
	    printf("%d\t",q->data[i]);
      printf("\n");
}
#endif
