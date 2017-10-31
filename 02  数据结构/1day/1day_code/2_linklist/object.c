/*
   2、用单向链表实现数据逆转，首先建立一个包含若干整数的单向链表，然后参考讲义的例子实现数据的逆转。（比如说把1，2，3，4，5逆转成5，4，3，2，1）
 */

#include "linklist.h"

void sort_linklist(link_plist l);
int main(void)
{
      link_plist l;

      //初始化单向链表
      init_linklist(&l);

      //创建单向链表
      create_linklist(l);

      //对单向链表逆序
      sort_linklist(l);
      return 0;
}

void sort_linklist(link_plist l)
{
      link_plist p,t;

      p = l->next;
      l->next  = NULL;
      while(p != NULL){
	    t = p;
	    p = p->next;
	    insert_linklist(l,t);

	    show_linklist(l);
      }
}
