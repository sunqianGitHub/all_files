#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc,char *argv[])
{

      DIR * dp;
      struct dirent *dip;

      dp = opendir(argv[1]);
      if(NULL == dp)
      {
	    perror("opendir failed");
	    exit(1);
      }

      //     printf("%s\n",readdir(dp)->d_name);

#if 0
      //有缺陷error
      while(readdir(dp) != NULL)
      {
	    printf("%s\n",readdir(dp)->d_name);
      }
#endif

#if 1     
     while(( dip = readdir(dp))!=NULL)
      {
	    printf("%s\n",dip->d_name);
      }
#endif

      return 0;
}
