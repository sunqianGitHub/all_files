#include "seqstack.h"


int main(void)
{
      datatype data,m,t;
      seq_pstack s;

      init_seqstack(&s);

      printf("请输入十进制数:");
      scanf("%d",&data);
      
      m = data;

      if(data < 0)
	    data = -data;

      while(data){
	    if(!push_seqstack(s,data%8))
		  goto err;
	    data /= 8;
      }
      if(m < 0)
	    printf("十进制数:%d 转换成八进制数为:-0",m);
      else
	    printf("十进制数:%d 转换成八进制数为:0",m);
      while(!isempty_seqstack(s)){
	    pop_seqstack(s,&t);
	    printf("%d",t);
      }
      printf("\n");
err:
      return 0;
}
