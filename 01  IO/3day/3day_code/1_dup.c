#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
      char buf[BUFSIZ];
      int fd;

      while(1)
      {
	    fgets(buf,BUFSIZ,stdin);
	    //修改文件描述符
//	    fd = dup(STDOUT_FILENO);
//	    write(STDOUT_FILENO,buf,strlen(buf));
	    //把STDOUT_FILENO复制给fd，赋值
	    //重定向文件描述符
	    dup2(STDOUT_FILENO,fd);
	    write(fd,buf,strlen(buf));
      }




      return 0;
}
