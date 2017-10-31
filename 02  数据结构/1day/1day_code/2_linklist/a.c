#include <stdio.h>

int x = 123;

void fun2(int *b)
{
      *b = 100;
}
void fun4(int ** q)
{
      *q = &x;
}

int main(void)
{
      int a;
      int *p;

//      fun1(a);	  //值传递：不能在被调用函数中修改实参
      fun2(&a);	  //地址传递：可以在被调用函数中修改实参
      printf("a  = %d\n",a);

  //    fun3(p);	  //值传递：不能在被调用函数中修改实参
      fun4(&p);	  //地址传递:可以在被调用函数中修改实参
      printf("*p = %d\n",*p);
      return 0;
}
