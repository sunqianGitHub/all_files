#include <stdio.h>
void menu1(void)
{
      printf("******  航班查询系统  ***********\n");
      printf("******  1.录入信息  ***********\n");
      printf("******  2.查询航班信息  ***********\n");
      printf("******  3.退出系统  ***********\n");
}
void menu2(void)
{
      printf("录入信息:\n");
      printf("****** 1.直接录入 ********\n");
      printf("****** 2.从文件中加载信息 ********\n");
      printf("****** 3.返回上一层 ********\n");
}
void menu3(void)
{
      printf("查询信息:\n");
      printf("****** 1.按起飞时间查询 ********\n");
      printf("****** 2.按目的地查询 ********\n");
      printf("****** 3.返回上一层 ********\n");
}
