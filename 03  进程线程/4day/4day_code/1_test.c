#include <stdio.h>
#include <unistd.h>


void fun(int n)
{
      int i;
      for( i = 0; i < 5; i++){
	    printf("this is fun!\n");
	    sleep(1);
      }
}

int main(void)
{
      int i;
      
      fun(5);
      for(i = 0; i < 5; i++){
	    printf("this is main!\n");
	    sleep(1);
      }
      return 0;
}
