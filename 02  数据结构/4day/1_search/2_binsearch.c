#include <stdio.h>

#define N 12

void show(int a[])
{
      int i;
      for(i = 0; i < N; i++)
	    printf("%d\t",a[i]);
      printf("\n");
}
//折半查找算法
int binsearch(int a[],int key)
{
      int low,high,mid;
      for(low = 0,high = N-1;low <= high; ){
	    mid = (low + high) / 2;
	    if(key == a[mid])
		  return mid;
	    else if(key > a[mid])
		  low = mid + 1;
	    else
		  high = mid - 1;
      }
      return -1;
}

int main(void)
{
      int a[] = {3,12,18,20,32,55,60,68,80,86,90,100};
      int i,key;
      char ch;
      
      while(1){
	    show(a);
	    printf("请输入要查找的关键字:");
	    scanf("%d",&key);
	    i = binsearch(a,key);
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
}
