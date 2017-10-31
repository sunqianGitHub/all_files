#include <stdio.h>
#include <time.h>


int main(void)
{
      time_t tm,tm1;

      time(&tm);
      //打印秒数
      printf("%ld\n",tm);
      //转换成日历时间 
      printf("%s",ctime(&tm));

      //本地时间
      struct tm *tp;
      tp = localtime(&tm);
      printf("%d-%d-%d %d:%d:%d\n",tp->tm_year+1900,tp->tm_mon+1,\
		  tp->tm_mday,tp->tm_hour,tp->tm_min,tp->tm_sec);

   //   printf("%s\n",&asctime(tp));//error	    
      printf("%s",asctime(tp));	    


      return 0;
}
