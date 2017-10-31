#include <stdio.h>
#include <stdlib.h>

struct student{
      int num;
      char name[20];
      float high;
      float weight;
};

int main(int argc,char *argv[])
{
      FILE * fp;
      int b=0;
      int c[5];

      if(argc != 2)
      {
	    printf("usage : %s <filename>\n",argv[0]);
	    exit(1);
      }

      fp = fopen(argv[1],"r");
      if(NULL == fp)
      {
	    perror("fopen failed");
	    exit(1);
      }
#if 0
      fread(&b,sizeof(int),1,fp);
      printf("b=%d\n",b);
#endif
#if 0
      int i;
      fread(c,sizeof(int),5,fp);
      for(i=0;i<5;i++)
	    printf("%d\t",c[i]);
      printf("\n");
#endif
      int i;
      struct student st[5];
      fread(st,sizeof(struct student),5,fp);
      for(i=0;i<5;i++)
	    printf("%d\t%s\t%f\t%f\n",st[i].num,st[i].name,\
				      st[i].high,st[i].weight);

      return 0;
}
