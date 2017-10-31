#include "linkstack.h"


int main(void)
{
      datatype data,m,t;
      link_pstack top;  //定义一个指向栈顶的指针:top

      init_linkstack(&top);

      printf("请输入十进制数:");
      scanf("%d",&data);
      
      m = data;

      if(data < 0)
	    data = -data;

      while(data){
	    if(!push_linkstack(&top,data%8))
		  goto err;
	    data /= 8;
      }
      if(m < 0)
	    printf("十进制数:%d 转换成八进制数为:-0",m);
      else
	    printf("十进制数:%d 转换成八进制数为:0",m);
      while(!isempty_linkstack(top)){
	    pop_linkstack(&top,&t);
	    printf("%d",t);
      }
      printf("\n");
err:
      return 0;
}
