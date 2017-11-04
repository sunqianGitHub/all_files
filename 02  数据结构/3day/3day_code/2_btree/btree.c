#include "btree.h"
#include "seqqueue.h"
#include "linkstack.h"

#if 0
btree_pnode create_btree(void)
{
      btree_pnode t;
      datatype_bt ch;

      scanf("%c",&ch);
      if(ch == '#')
	    t = NULL;
      else{
	    //创建根结点
	    t = (btree_pnode)malloc(sizeof(btree_node));
	    if(NULL == t){
		  perror("malloc");
		  exit(1);
	    }
	    t->data = ch;
	    t->lchild = create_btree(); //创建左子树
	    t->rchild = create_btree(); //创建右子树
      }
      return t;
}
#else
void create_btree(btree_pnode *T)
{
      datatype_bt ch;
      scanf("%c",&ch);
      if(ch == '#')
	    *T = NULL;
      else{
	    //创建根结点
	    *T = (btree_pnode)malloc(sizeof(btree_node));
	    if(NULL == *T){
		  perror("malloc");
		  exit(1);
	    }
	    (*T)->data = ch;
	    //创建左子树
	    create_btree(&(*T)->lchild);
	    //创建右子树
	    create_btree(&(*T)->rchild);
      }
}
#endif

//先序递归遍历
void preorder(btree_pnode t)
{
      
      if(t != NULL){
	    //访问根结点
	    printf("%c",t->data);
	    //先序遍历左子树
	    preorder(t->lchild);
	    //先序遍历右子树
	    preorder(t->rchild);
      }
}
//先序非递归算法
void preorder_un(btree_pnode t)
{
      link_pstack top;
      init_linkstack(&top);  //初始化空栈

      while(t != NULL || !isempty_linkstack(top)){
	    while(t !=NULL){
		  printf("%c",t->data);
		  if(t->rchild != NULL)
			push_linkstack(&top,t->rchild);
		  t = t->lchild;
	    }
	    if(!isempty_linkstack(top))
		  pop_linkstack(&top,&t);
      }
}
//中序遍历
void midorder(btree_pnode t)
{
      
      if(t != NULL){
	    //中序遍历左子树
	    midorder(t->lchild);
	    //访问根结点
	    printf("%c",t->data);
	    //中序遍历右子树
	    midorder(t->rchild);
      }
}
//后序遍历
void postorder(btree_pnode t)
{
      
      if(t != NULL){
	    //后序遍历左子树
	    postorder(t->lchild);
	    //后序遍历右子树
	    postorder(t->rchild);
	    //访问根结点
	    printf("%c",t->data);
      }
}
//按层遍历
void levelorder(btree_pnode t)
{
      seq_pqueue q;

      init_seqqueue(&q); //初始化顺序队列
      while(t!=NULL){
	    printf("%c",t->data);  //访问数据
	    if(t->lchild != NULL)
		  in_seqqueue(q,t->lchild);
	    if(t->rchild != NULL)
		  in_seqqueue(q,t->rchild);
	    if(!isempty_seqqueue(q))
		  out_seqqueue(q,&t);
	    else
		  break;
      }
}

void travel(char const *str,void (*order)(btree_pnode),btree_pnode t)
{
      printf("%s",str);
      order(t);
      printf("\n");
}
