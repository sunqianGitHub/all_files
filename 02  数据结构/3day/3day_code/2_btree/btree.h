#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char datatype_bt;

typedef struct btreenode{
      datatype_bt data;
     struct btreenode *lchild,*rchild; 
}btree_node,*btree_pnode;

extern void create_btree(btree_pnode *T);
extern void preorder(btree_pnode t);
extern void preorder_un(btree_pnode t);
extern void midorder(btree_pnode t);
extern void postorder(btree_pnode t);
extern void levelorder(btree_pnode t);
extern void travel(char const *str,void (*order)(btree_pnode),btree_pnode t);
#endif
