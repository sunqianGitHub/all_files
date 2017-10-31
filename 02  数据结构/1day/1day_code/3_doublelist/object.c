/*
4、用双向循环链表实顺序递增存储若干自然数，比如输入一个整数10，则建立一个双向循环链表，里面的每个节点分别存放1，2，3，4，5，6，7，8，9，10，然后通过某些操作，将其重新排列成1，3，5，7，9，10，8，6，4，2，即奇数升序偶数降序，并在屏幕上打印出来。
 */

#include "doublelist.h"

void sort_doublelist(double_plist l);
int main(void)
{
      double_plist l;

      //初始化单向链表
      init_doublelist(&l);

      //创建单向链表
      create_doublelist(l);

      //对双向链表奇数升序偶数降序
      sort_doublelist(l);
      return 0;
}

void sort_doublelist(double_plist l)
{
      double_plist p,t;
      
      p = l->prev;
      while(p != l){
	    if(p->data % 2 != 0)  //奇数不变，p向前移动
		  p = p->prev;
	    else{  //偶数，剪切，并插入到表尾
		  t = p;
		  p = p->prev;
		  
		  //剪切t指向的结点
		  del_doublelist(t);
		  //将t指向的结点插入到表尾
		  insert_doublelist_tail(l,t);
		  show_doublelist(l);
	    }
      }

}
