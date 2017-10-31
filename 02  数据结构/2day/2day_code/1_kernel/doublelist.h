#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef int datatype;

typedef struct doublelist{
      datatype data;
      struct list_head list;   //必须定义struct list_head变量，不能定义成指针
}double_list,*double_plist;

extern void init_doublelist(double_plist *L);
extern void show_doublelist(double_plist l);
extern void create_doublelist(double_plist l);
#endif
