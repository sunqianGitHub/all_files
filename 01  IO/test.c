#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
      FILE *fp1,*fp2;
      long int len,i;
      char s[1];

      if(argc !=3)
      {
	    printf("Usage %s <SRC-file> <DSK-file>",argv[0]);
	    exit(1);
      }
      
      fp1 = fopen(argv[1],"r");
      if(NULL == fp1)
      {
	    perror("fopen faile");
	    exit(1);
      }

      fp2 = fopen(argv[2],"w");
      if(NULL == fp1)
      {
	    perror("fopen faile");
	    exit(1);
      }

      fseek(fp1,0,SEEK_END);
      len = ftell(fp1);
      for(i=len-1; i>=0; i--){
	     fseek(fp1,-(len-i),SEEK_END);
	    // fgets(s,2,fp1);
	     fread(s,sizeof(s),1,fp1);
	     fwrite(s,sizeof(s),1,fp2);
      }

      return 0;
}
