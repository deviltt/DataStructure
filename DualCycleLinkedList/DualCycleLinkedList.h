#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include "./Status.h"

typedef int LElemType_DC;

typedef struct DuLNode{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode;

typedef DuLNode *DuLinkList;

//typedef int Status;

Status InitList_DuL(DuLinkList *L);

Status ClearList_DuL(DuLinkList L);

void DestroyList_DuL(DuLinkList *L);

Status ListEmpty_DuL(DuLinkList L);

int ListLength_DuL(DuLinkList L);

Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);

int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC));

Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);

Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);

DuLinkList GetElemPtr_DuL(DuLinkList L, int i);

Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);

Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);

void ListTraverse_DuL(DuLinkList L, void (Visit)(LElemType_DC));

#endif
