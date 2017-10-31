#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>


void file_lstat(char *filename)
{
      struct stat buf;
      struct tm *tp;
      struct group * gp;
      int ret;

      //获取filename的文件信息
      ret = lstat(filename,&buf);
      if(ret<0)
      {
	    perror("lstat failed");
	    exit(1);
      }

      //打印文件类型
      if(S_ISREG(buf.st_mode))
	    printf("-");
      else if(S_ISBLK(buf.st_mode))
	    printf("b");
      else if(S_ISCHR(buf.st_mode))
	    printf("c");
      else if(S_ISFIFO(buf.st_mode))
	    printf("p");
      else if(S_ISDIR(buf.st_mode))
	    printf("d");
      else if(S_ISLNK(buf.st_mode))
	    printf("l");
      else if(S_ISSOCK(buf.st_mode))
	    printf("s");

      //打印权限
      int i;
      char str[] = "xwr-";
      for(i=8;i>=0;i--)
	    if(buf.st_mode & 1<<i)
		  printf("%c",str[i%3]);
	    else
		  printf("%c",str[3]);

      //打印链接数
      printf(" %u ",buf.st_nlink);
      //打印用户名
      printf("%s ",getpwuid(buf.st_uid)->pw_name);
      //打印组名
      printf("%s ",getgrgid(buf.st_gid)->gr_name);
      //      gp = getgrgid(buf.st_gid);
      //      printf("%s ",gp->gr_name);
      //打印文件大小
      printf("%ld ",buf.st_size);
      //打印状态最后修改时间
      tp = localtime(&buf.st_ctime);
      printf("%d-%d-%d %d:%d ",tp->tm_year+1900,\
		  tp->tm_mon+1,tp->tm_mday,\
		  tp->tm_hour,tp->tm_min);
      //打印文件名
      printf("%s\n",filename);

}

int main(int argc,char *argv[])
{     
      char buf[BUFSIZ];

      DIR * dp;
      struct dirent *dip;
      struct stat dat;

      if(lstat(argv[1],&dat)<0)
      {
	    perror("lstat ");
	    exit(1);
      }

      if(S_ISDIR(dat.st_mode))
      {
	    dp = opendir(argv[1]);
	    if(NULL == dp)
	    {
		  perror("opendir failed");
		  exit(1);
	    }

	    while(( dip = readdir(dp))!=NULL)
	    {
		  //	    printf("%s\n",dip->d_name);
		  sprintf(buf,"%s",dip->d_name);
		  file_lstat(buf);
	    }

      }
      else if(S_ISREG(dat.st_mode))
	    file_lstat(argv[1]);


      return 0;
}
