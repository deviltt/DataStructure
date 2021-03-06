#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C

#include "SequenceList.h"

Status InitList_Sq(SqList *L){		//线性表初始化
	(*L).elem = (LElemType_Sq *)malloc(LIST_INIT_SIZE * sizeof(LElemType_Sq));
	if(!(*L).elem)
		exit(OVERFLOW);

	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
}

void ClearList_Sq(SqList *L){		//清除线性表
	(*L).length = 0;
}

void DestroyList_Sq(SqList *L){		//撤销线性表
	free((*L).elem);

	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
}

int ListEmpty_Sq(SqList L){		//判断线性表为空
	return L.length == 0 ? TRUE : FALSE;
}

int ListLength_Sq(SqList L){		
	return L.length;
}

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e){		
	if(i < 1 || i > L.length)
		return ERROR;
	else
		*e = L.elem[i-1];

	return OK;
}

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq)){	
	int i = 1;

	while(i <= L.length && !Compare(e, L.elem[i-1]))
		i++;

	if(i <= L.length)
		return i;
	else
		return 0;
}

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e){
	int i = 1;

	if(L.elem[0] != cur_e){
		while(i < L.length && L.elem[i-1] != cur_e)
			++i;

		if(i < L.length){
			*pre_e = L.elem[i-2];
			return OK;
		}
	}
	
	return ERROR;
}

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e){
	int i = 0;

	while(i < L.length && L.elem[i] != cur_e)
		++i;

	if(i < L.length-1){
		*next_e = L.elem[i+1];
		return OK;
	}	

	return ERROR;
}

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e){
	LElemType_Sq *newbase;
	LElemType_Sq *p, *q;

	if(i < 1 || i > (*L).length + 1)
		return ERROR;

	if((*L).length >= (*L).listsize){
		newbase = (LElemType_Sq *)realloc((*L).elem, ((*L).listsize + LISTINCREMENT) * sizeof(LElemType_Sq));

		if(!newbase)
			exit(OVERFLOW);

		(*L).elem = newbase;
		(*L).listsize += LISTINCREMENT;
	}

	q = &(*L).elem[i-1];

	for(p = &(*L).elem[(*L).length - 1]; p >= q; --p)
		*(p+1) = *p;

	*q = e;

	(*L).length++;

	return OK;
}

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e){
	int j;
	LElemType_Sq *p, *q;

	if(i < 1 || i > (*L).length)
		return ERROR;

	p = &(*L).elem[i-1];	//p标记要删除的位置，以保存该位置的值
	*e = *p;	//用e保存该位置的值
	q = (*L).elem + (*L).length - 1;	//q为指向该线性表最后一个元素的指针
/*
	for(++p; p <= q; ++p)
		*(p-1) = *p;	
*/

	for(p; p < q; p++)
		*p = *(p + 1);		//将位置i的元素删除后每个元素前移一位

	(*L).length--;	//线性表的总长度减一

	return OK;
}

Status ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq)){
	int i;

	for(i = 0; i < L.length; i++)
		Visit(L.elem[i]);

	return OK;
}

#endif
