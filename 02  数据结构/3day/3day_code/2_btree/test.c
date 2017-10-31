#include "btree.h"

int main(void)
{
      btree_pnode t;
      
      create_btree(&t);

      travel("先序遍历序列:",preorder,t);
      travel("先序非递归遍历序列:",preorder_un,t);
      travel("中序遍历序列:",midorder,t);
      travel("后序遍历序列:",postorder,t);
      travel("按层遍历序列:",levelorder,t);
      return 0;
}

