#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "./Status.h"

typedef int QElemType_L;

typedef struct QNode{
	QElemType_L data;
	struct QNode *next;
}QNode;

typedef QNode *QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue_L(LinkQueue *Q);

void ClearQueue_L(LinkQueue *Q);

void DestroyQueue_L(LinkQueue *Q);

Status QueueEmtpy_L(LinkQueue Q);

Status QueueLength_L(LinkQueue Q);

Status GetHead_L(LinkQueue Q, QElemType_L *e);

Status EnQueue_L(LinkQueue *Q, QElemType_L e);

Status DeQueue_L(LinkQueue *Q, QElemType_L *e);

void QueueTraverse_L(LinkQueue Q, void (Visit)(QElemType_L));

#endif
