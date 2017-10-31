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

      FILE *fp;
      int a=100;
      int b[5]={1,2,3,4,5};

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      fp = fopen(argv[1],"w");
      if(NULL == fp)
      {
	    perror("fopen failed");
	    exit(1);
      }

//存放一个数到文件中
//      fwrite(&a,sizeof(int),1,fp);
//存放一个数组到文件中
//      fwrite(b,sizeof(int),5,fp);

      struct student st[5]={{1001,"lindan",1.78,160},
			    {1002,"xiaoqi",1.80,102},
			    {1003,"baobao",1.62,120},
			    {1004,"laosong",1.75,160},
			    {1005,"xiaoqiao",1.70,150}};
      fwrite(st,sizeof(struct student),5,fp);

      return 0;
}
