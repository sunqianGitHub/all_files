#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int datatype;

typedef struct linklist{
      datatype data;
      struct linklist *next;
}link_list,*link_plist;

extern void init_linklist(link_plist *L);
extern void insert_linklist(link_plist p,link_plist new);
extern void del_linklist(link_plist p);
extern bool isempty_linklist(link_plist l);
extern void show_linklist(link_plist l);
extern void create_linklist(link_plist l);
#endif
