#ifndef BINARYTREE_C
#define BINARYTREE_C

#include "BinaryTree.h"

void InitBiTree(BiTree *T)
{
	*T = NULL;
}

void ClearBiTree(BiTree *T)
{
	if(*T){
		if((*T)->lchild)
			ClearBiTree(&((*T)->lchild));
		if((*T)->rchild)
			ClearBiTree(&((*T)->rchild));

		free(*T);

		*T = NULL;
	}
}

void DestroyBiTree(BiTree *T)
{

}

Status BiTreeEmpty(BiTree T)
{
	return T == NULL ? TRUE : ERROR;
}

Status CreateBiTree(FILE *fp, BiTree *T)
{
	char ch;

	Scanf(fp, "%c", &ch);

	if(ch == '^')
		*T = NULL;
	else{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!(*T))
			exit(OVERFLOW);
		(*T)->data = ch;
		CreateBiTree(fp, &(*T)->lchild);
		CreateBiTree(fp, &(*T)->rchild);
	}

	return OK;
}

Status BiTreeLength(BiTree T)
{
	Node node[100];
	int i, len;

	i = len = 0;

	if(T){
		node[i].left = T->lchild;
		node[i].right = T->rchild;
		node[i].n = 1;
		if(node[i].n > len)
			len = node[i].n;

		while(i >= 0){
			while(node[i].left){
				
			}
		}
	}
}
