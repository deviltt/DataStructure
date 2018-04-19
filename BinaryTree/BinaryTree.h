#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char TElemType;

typedef struct BiTNode{
	TELemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode;

typedef BiTNode *BiTree;

typedef BiTree SElemType_Sq;

typedef struct{
	BiTree left;
	BiTree right;
	int n;
}Node;

#endif
