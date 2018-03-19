#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ

typedef int LElemType_Sq;

#endif

typedef struct{
	LElemType_Sq *elem;
	int length;
	int listsize;
}

Status InitList_Sq(Sqlist *L);	//初始化顺序表

void ClearList_Sq(SqList *L);	//清空顺序表

void DestroyList_Sq(SqList *L);	//销毁顺序表

Status ListEmpty_Sq(SqList *L);	//判空

int ListLength_Sq(SqList *L);	//

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq e);

Status ListTraverses_Sq(SqList L, void(Visit)(LElemType_Sq));

#endif
