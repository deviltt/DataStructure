#ifndef CYLSEQQUEUE_H
#define CYLSEQQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include "./Status.h"

#define MAXQSIZE 1000

typedef int QElemType_CSq;

typedef struct{
	QElemType_CSq *base;
	int front;
	int rear;
}CSqQueue;

Status InitQueue_CSq(CSqQueue *Q);

void ClearQueue_CSq(CSqQueue *Q);

void DestroyQueue_CSq(CSqQueue *Q);

Status QueueEmpty_CSq(CSqQueue Q);

int QueueLength_CSq(CSqQueue Q);

Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e);

Status EnQueue_CSq(CSqQueue *Q, QElemTypq_CSq e);

Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e);

void QueueTraverse_CSq(CSqQueue Q, void (Visit)(QElemType_CSq));

#endif
