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
      INIT_LIST_HEAD(&(*L)->list);
}

//遍历
void show_doublelist(double_plist l)
{
      double_plist p;
      list_for_each_entry(p,&l->list,list)
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
      list_add_tail(&new->list,&l->list);
      show_doublelist(l);
    }
}
