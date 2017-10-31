#include "linklist.h"

//初始化
void init_linklist(link_plist *L)
{
      //1.申请空间
      *L = (link_plist)malloc(sizeof(link_list));
      if(NULL == *L){
	    perror("malloc");
	    exit(1);
      }
      //2.头结点的next为空
      (*L)->next = NULL;
}
//插入
void insert_linklist(link_plist p,link_plist new)
{
      new->next = p->next;
      p->next = new;
}
//删除
void del_linklist(link_plist p)
{
      p->next = p->next->next;
}
//判断顺序表是否为空
bool isempty_linklist(link_plist l)
{
      if(l->next == NULL)
	    return true;
      else
	    return false;
}
//遍历
void show_linklist(link_plist l)
{
      link_plist p;
      for(p = l->next; p != NULL; p = p->next)
	    printf("%d\t",p->data);
      printf("\n");
}

//创建单向链表
void create_linklist(link_plist l)
{
     int n,i;
     link_plist new,p;
    printf("请输入链表长度:"); 
    scanf("%d",&n);

    for(i = 0, p = l; i < n; i++){
      new = (link_plist)malloc(sizeof(link_list));
      if(NULL == new){
	    perror("malloc");
	    exit(1);
      }
      scanf("%d",&new->data);
      //将new结点插入到链表中
      insert_linklist(p,new);
      show_linklist(l);
      p = p->next;  //让p指向表尾
    }
}
