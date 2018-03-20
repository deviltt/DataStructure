#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define LIST_INIT_SIZE 100	//顺序表存储空间的初始分配量
#define LISTINCREMENT 10	//顺序表存储空间的分配增量

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ

typedef int LElemType_Sq;	

#endif

typedef struct{
	LElemType_Sq *elem;	//顺序表基地址
	int length;		//当前顺序表长度
	int listsize;		//当前分配的存储容量
}SqList;			

Status InitList_Sq(SqList *L);	//初始化顺序表

void ClearList_Sq(SqList *L);	//清空顺序表

void DestroyList_Sq(SqList *L);	//销毁顺序表

Status ListEmpty_Sq(SqList L);	//判空

int ListLength_Sq(SqList L);	//顺序表的长度

Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);	//用e接收顺序表中第i个元素

int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));//返回顺序表中首个与e满足Compare关系的位序

Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);		//用pre_e接收cur_e的前驱

Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);		//用next_e接收cur_e的后继

Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);		//在顺序表i处出插入元素e

Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);	//在顺序表中i处元素，并用e返回

Status ListTraverses_Sq(SqList L, void(Visit)(LElemType_Sq));	//以visit函数访问顺序表

#endif
