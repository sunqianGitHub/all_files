#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



int main(void)
{
      char buf[BUFSIZ];
      int ret;

      printf("BUFSIZ = %d\n",BUFSIZ);

      ret = read(STDIN_FILENO,buf,BUFSIZ);
      if(ret<0)
      {
	    fprintf(stdout,"read failed");
	    exit(1);
      }
      else if(ret == 0)
      {
	    exit(1);
      }
      else
      {
	    printf("%s\n",buf);
      }

      return 0;
}
