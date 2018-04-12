#ifndef SEQUENCESTACK_H
#define SEQUENCESTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "./Status.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10
/*
#if !define MAZE_H		&& \
    !define EXPRESSION_H	&& \
    !define BINARYTREE		&& \
    !define CHILDSIBLINGTREE	&& \
    !define Question_8
*/
typedef int SElemType_Sq;

//#endif

typedef struct{
	SElemType_Sq *base;
	SElemType_Sq *top;
	int stacksize;
}SqStack;

Status InitStack_Sq(SqStack *S);

Status DestroyStack_Sq(SqStack *S);

Status ClearStack_Sq(SqStack *S);

Status StackEmpty_Sq(SqStack S);

int StackLength_Sq(SqStack S);

Status GetTop_Sq(SqStack S, SElemType_Sq *e);

Status Push_Sq(SqStack *S, SElemType_Sq e);

Status Pop_Sq(SqStack *S, SElemType_Sq *e);

Status StackTraverse_Sq(SqStack S, void (Visit)(SElemType_Sq));

#endif
