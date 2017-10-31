#include <stdio.h>

#define N 11

void show(int a[])
{
      int i;
      for(i = 0; i < N; i++)
	    printf("%d\t",a[i]);
      printf("\n");
}
//顺序查找算法
int seqsearch(int a[],int key)
{
      int i;
      for(i = N-1;i >= 0; i--)
	    if(key == a[i])
		  return i;
      return i;
}

int main(void)
{
      int a[] = {2,8,4,9,6,3,5,7,1,12,11};
      int i,key;
      char ch;
      
      while(1){
	    show(a);
	    printf("请输入要查找的关键字:");
	    scanf("%d",&key);
	    i = seqsearch(a,key);
	    if(i == -1){   //查找失败
		  printf("查找失败!\n");
		  break;
	    }else{	//查找成功
		  printf("查找成功!\n");
		  printf("要查找的记录在%d位置!\n",i);
	    }
	    printf("是否继续?(Y/y)");
	    while(getchar() != '\n');
	    scanf("%c",&ch);
	    if(ch != 'Y' && ch != 'y')
		  break;
      }
      return 0;
}
