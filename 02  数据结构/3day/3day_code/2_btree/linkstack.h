#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "btree.h"

typedef btree_pnode datatype;

typedef struct linkstack{
      datatype data;
      struct linkstack *next;
}link_stack,*link_pstack;

extern void init_linkstack(link_pstack *Top);
extern bool push_linkstack(link_pstack *Top,datatype d);
extern void pop_linkstack(link_pstack *Top,datatype *D);
extern bool isempty_linkstack(link_pstack top);
//extern void show_linkstack(link_pstack top);
#endif
