#include "seqlist.h"

//初始化
#if 0
seq_plist init_seqlist()
{
      seq_plist l;
      //1.申请空间
      l = (seq_plist)malloc(sizeof(seq_list));
      if(NULL == l){
	    perror("malloc");
	    exit(1);
      }
      //2.last 加 1
      l->last = -1;

      return l;
}
#else
void init_seqlist(seq_plist *L)
{
      //1.申请空间
      *L = (seq_plist)malloc(sizeof(seq_list));
      if(NULL == *L){
	    perror("malloc");
	    exit(1);
      }
      //2.last 加 1
      (*L)->last = -1;
}
#endif
//插入
void insert_seqlist(seq_plist l,int i,datatype data)
{
      int j;
      if(isfull_seqlist(l)){
	    printf("表已满!\n");
	    return ;
      }
      
      for(j = l->last; j>= i; j--)
	    l->data[j+1] = l->data[j];

      l->data[i] = data;

      l->last++;
}
//删除
void del_seqlist(seq_plist l,int i)
{
      int j;
      if(isempty_seqlist(l)){
	    printf("表已空!\n");
	    return ;
      }
      
      for(j = i; j < l->last; j++)
	    l->data[j] = l->data[j+1];

      l->last--;

}
//判断顺序表是否为空
bool isempty_seqlist(seq_plist l)
{
      if(l->last == -1)
	    return true;
      else
	    return false;
}
//判断顺序表是否为满
bool isfull_seqlist(seq_plist l)
{
      if(l->last == SIZE-1)
	    return true;
      else
	    return false;
}
//遍历
void show_seqlist(seq_plist l)
{
      int i;
      for(i = 0; i <= l->last; i++)
	    printf("%d\t",l->data[i]);
      printf("\n");
}
