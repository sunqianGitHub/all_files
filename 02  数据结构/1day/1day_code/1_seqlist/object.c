/*
 1、用顺序表存储一些正整数，输入正整数表示插入数据（比如输入3表示插入3），输入负整数表示删除数据（比如输入-2表示删除2），输入字符表示退出程序。插入和删除的过程中保持该表递增有序。
 */

#include "seqlist.h"

void insert(seq_plist l,datatype data);
void del(seq_plist l,datatype data);
int main(void)
{
      seq_plist l;
      datatype data;
      int ret;

#if 0
      l = init_seqlist();  // 初始化
#else
      init_seqlist(&l);
#endif
      while(1){
	    printf("请输入一个整数:");
	    ret = scanf("%d",&data);
	    if(ret != 1){ //输入为字符
		  printf("Bye-bye!\n");
		  exit(1);
	    }else if(data > 0){  //输入为正，插入该整数
		  insert(l,data);
		  show_seqlist(l);		  
	    }else if(data < 0){ //输入为负，删除对应的正数
		  del(l,-data);
		  show_seqlist(l);
	    }
      }

      return 0;
}

void insert(seq_plist l,datatype data)
{
      int i;
      for(i = 0; i <= l->last; i++)
	    if(data < l->data[i])
		  break;
      insert_seqlist(l,i,data);
}

void del(seq_plist l,datatype data)
{
      int i;
      for(i = 0; i <= l->last; i++)
	    if(data == l->data[i])
		  break;
      if(i > l->last)
	    printf("数据不存在!\n");
      else
	    del_seqlist(l,i);
}
