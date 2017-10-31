#include "seqstack.h"

//初始化栈
void init_seqstack(seq_pstack *S)
{
      *S = (seq_pstack)malloc(sizeof(seq_stack));
      if(NULL == *S){
	    perror("malloc");
	    exit(1);
      }

      (*S)->top = -1;
}

//入栈
bool push_seqstack(seq_pstack s,datatype d)
{
      if(isfull_seqstack(s)){
	    printf("栈是满的!\n");
	    return ;
      }

      s->top++;
      s->data[s->top] = d;
}
//出栈
void   pop_seqstack(seq_pstack s,datatype *D)
{
      if(isempty_seqstack(s)){
	    printf("栈是空的!\n");
	    return ;
      }
      *D = s->data[s->top];
      s->top--;
}

bool isempty_seqstack(seq_pstack s)
{
      if(s->top == -1)
	    return true;
      else
	    return false;
}
bool isfull_seqstack(seq_pstack s)
{
      if(s->top == SIZE-1)
	    return true;
      else
	    return false;
}

void show_seqstack(seq_pstack s)
{
      int i;
      for(i = s->top; i >= 0; i--)
	    printf("%d\t",s->data[i]);
      printf("\n");
}
