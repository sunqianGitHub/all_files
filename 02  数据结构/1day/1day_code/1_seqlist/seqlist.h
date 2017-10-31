#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
typedef int datatype;

typedef struct seqlist{
      datatype data[SIZE];
      int last;
}seq_list,*seq_plist;

#if 0
extern seq_plist init_seqlist();
#else
void init_seqlist(seq_plist *L);
#endif
extern void insert_seqlist(seq_plist l,int i,datatype data);
extern void del_seqlist(seq_plist l,int i);
extern bool isempty_seqlist(seq_plist l);
extern bool isfull_seqlist(seq_plist l);
extern void show_seqlist(seq_plist l);
#endif
