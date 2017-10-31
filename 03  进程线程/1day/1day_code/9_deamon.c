#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


void init()
{
      int pid;
      /***********************start***********************/
      //1.创建子进程
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0)
	    exit(0);
      //2.创建新会话
      if(setsid() < 0){
	    perror("setsid");
	    exit(1);
      }

      //3.创建子进程
      if((pid = fork()) < 0){
	    perror("fork");
	    exit(1);
      }else if(pid > 0)
	    exit(0);
      //4.关闭所有的文件描述符
      int i,max_fd = sysconf(_SC_OPEN_MAX);
      for (i = 0; i < max_fd;i++)
	    close(i);
      //5.umask (0) 清除旧有的文件掩码
      umask(0);
      //6.修改当前目录为根目录
       chdir ("/");
       //7.重定向标准文件描述符
       open("/dev/null",O_RDWR);
       dup(0);
       dup(0);
      /*************************end******************************/
}
//利用守护进程每隔一秒钟向文件中写入一条时间信息
int main(int argc,char **argv)
{
      FILE *fp;
      int count;
      time_t tm;
      char buf[BUFSIZ];

      init();  //初始化守护进程
      
      if((fp = fopen(argv[1],"a+")) == NULL){
	    //perror("error");
	    exit(1);
      }
      for(count = 0; fgets(buf,BUFSIZ,fp);count++);
     
     while(1){
	    time(&tm);
	    sprintf(buf,"%d:%s",count++,ctime(&tm));
	    fputs(buf,fp);
	    fflush(fp);
	    sleep(1);
     }
      
     fclose(fp);

     return 0;
}
