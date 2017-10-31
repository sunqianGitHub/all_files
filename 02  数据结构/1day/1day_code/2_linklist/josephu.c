#include "linklist.h"

void create_josephu(link_plist h);
void show_josephu(link_plist h);
void init_josephu(link_plist *L);
int josephu(link_plist h,int n);

int main(void)
{
      link_plist h;
      int ret;

      init_josephu(&h);

      create_josephu(h);

      ret = josephu(h,3);
      printf("last is %d\n",ret);
      return 0;
}
int josephu(link_plist h,int n)
{
      link_plist p = h,t;
      int i;
      while(p != p->next){
	    //找到要删除的结点前一个结点的地址
	    for(i = 0; i < n-2;i++)
		  p = p->next;
	    //删除p指向的结点后一个结点
	    t = p->next;
	    del_linklist(p);
	    p = t->next;  //让p指向下一次开始数的结点
	    printf("out:%d\t",t->data);
	    free(t);
      }
      printf("\n");
      return p->data;
}
void init_josephu(link_plist *L)
{
      //1.申请空间
      *L = (link_plist)malloc(sizeof(link_list));
      if(NULL == *L){
	    perror("malloc");
	    exit(1);
      }
      //2.头结点的next为空
      (*L)->next = *L;
}
void create_josephu(link_plist h)
{
      int n,i;
      link_plist new,p = h;

      printf("请输入链表长度:");
      scanf("%d",&n);
      for(i = 0; i < n; i++){
	    if(i== 0)
		  scanf("%d",&p->data);
	    else{
		  new = (link_plist)malloc(sizeof(link_list));
		  if(NULL == new){
			perror("malloc");
			exit(1);
		  }
		  scanf("%d",&new->data);

		  insert_linklist(p,new);
		  p = p->next;

	    }
	    show_josephu(h);
      }
}
void show_josephu(link_plist h)
{
      link_plist p;

      for(p = h; p->next != h; p = p->next)
	    printf("%d\t",p->data);
      printf("%d\n",p->data);
}
