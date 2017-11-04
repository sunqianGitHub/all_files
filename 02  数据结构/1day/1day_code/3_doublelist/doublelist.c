#include "doublelist.h"

//初始化
void init_doublelist(double_plist *L)
{
      //1.申请空间
      *L = (double_plist)malloc(sizeof(double_list));
      if(NULL == *L){
	    perror("malloc");
	    exit(1);
      }
      //2.头结点的next和prev都指向当前结点
      (*L)->next = *L;
      (*L)->prev = *L;
}
//h的后面插入new
void insert_doublelist(double_plist h,double_plist new)
{
      new->next = h->next;
      h->next->prev = new;
      new->prev = h;
      h->next = new;
}
//h的前面插入new
void insert_doublelist_tail(double_plist h,double_plist new)
{
      new->prev = h->prev;
      h->prev->next = new;
      new->next = h;
      h->prev = new;
}
//删除
void del_doublelist(double_plist p)
{
      p->next->prev = p->prev;
      p->prev->next = p->next;
}
//判断顺序表是否为空
bool isempty_doublelist(double_plist l)
{
      if(l->next == l)
	    return true;
      else
	    return false;
}
//遍历
void show_doublelist(double_plist l)
{
      double_plist p;
      for(p = l->next; p != l; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}

//创建双向循环链表
void create_doublelist(double_plist l)
{
     int n,i;
     double_plist new;
     printf("请输入链表长度:"); 
     scanf("%d",&n);

     for(i = 0; i < n; i++){
      new = (double_plist)malloc(sizeof(double_list));
      if(NULL == new){
	    perror("malloc");
	    exit(1);
      }
      scanf("%d",&new->data);
      //将new结点插入到链表中
      insert_doublelist_tail(l,new);
      show_doublelist(l);
    }
}
