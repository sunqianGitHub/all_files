#include "list.h"
#include <stdio.h>


struct A{
      int a;
      float b;
      char c;
};


int main(void)
{
      struct A st = {100,12.34,'H'};
      float *p;

      p = &st.b;

      struct A *ps;

      ps = list_entry(p,struct A,b);
      printf("a = %d\n",ps->a);
      printf("b = %f\n",ps->b);
      printf("c = %c\n",ps->c);

      return 0;
}
