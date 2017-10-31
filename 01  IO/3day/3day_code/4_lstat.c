#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>


int main(int argc,char *argv[])
{
      struct stat buf;
      struct tm *tp;
      struct group * gp;
      int ret;

      if(argc != 2)
      {
	    printf("usage: %s <filename>\n",argv[0]);
	    exit(1);
      }

      //获取argv[1]的文件信息
      ret = lstat(argv[1],&buf);
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
      printf("%s\n",argv[1]);

      return 0;
}
