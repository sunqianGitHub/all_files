#include "linkqueue.h"

//初始化栈
void init_linkqueue(link_pqueue *Q)
{
      //申请front和rear的空间
      *Q = (link_pqueue)malloc(sizeof(link_queue));
      if(NULL == *Q){
	    perror("malloc");
	    exit(1);
      }

      //申请头结点空间
      (*Q)->front = (queue_pnode)malloc(sizeof(queue_node));
      if(NULL == (*Q)->front){
	    perror("malloc");
	    exit(1);
      }
      (*Q)->front->next = NULL;

      (*Q)->rear = (*Q)->front;
}

//入队
bool in_linkqueue(link_pqueue q,datatype d)
{
      queue_pnode new;

      //创建一个新结点
      new = (queue_pnode)malloc(sizeof(queue_node));
      if(NULL == new){
	    perror("malloc");
	    return false;
      }
      new->data = d;

      new->next = q->rear->next;
      q->rear->next = new;      
      q->rear = q->rear->next;
      return true;
}
//出队
bool   out_linkqueue(link_pqueue q,datatype *D)
{
      queue_pnode t;

      if(isempty_linkqueue(q)){
	    printf("队列是空的!\n");
	    return false;
      }
      
      t = q->front;
      q->front = q->front->next;
      *D = q->front->data;
      free(t);
      return true;
}

bool isempty_linkqueue(link_pqueue q)
{
      if(q->rear == q->front)
	    return true;
      else
	    return false;
}

void show_linkqueue(link_pqueue q)
{
      queue_pnode p;
      for(p = q->front->next;p != NULL; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}
