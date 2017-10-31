#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

typedef struct doublelist{
      datatype data;
      struct doublelist *next,*prev;
}double_list,*double_plist;

extern void init_doublelist(double_plist *L);
extern void insert_doublelist(double_plist p,double_plist new);
extern void insert_doublelist_tail(double_plist h,double_plist new);
extern void del_doublelist(double_plist p);
extern bool isempty_doublelist(double_plist l);
extern void show_doublelist(double_plist l);
extern void create_doublelist(double_plist l);
#endif
