#include <stdio.h>
#include "SequenceList.c"

Status CmpGreater(LElemType_Sq e, LElemType_Sq data)
{
	return data > e ? TRUE : FALSE;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}

int mian(){
	SqList L;
	int i;
	LElemType_Sq e;

	printf("1\nFunction InitList_Sq test...\n");
	{
		printf("init Sequence L...\n");
		InitList_Sq(&L);
		printf("\n");
	}
	PressEnter;

	printf("4\nFunction ListEmpty_Sq test...\n");
	{
		ListEmpty_Sq(L) ? printf("L is empty!\n") : printf("no empty\n");
		printf("\n");
	}
	PressEnter;

	printf("10\nFunction ListInster_Sq test...\n");
	{
		for(i = 1; i <= 6; i++){
			printf("as show, insert at %dth with %d\n", i, 2*i);
			ListInsert_Sq(&L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("12\nFunction ListTraverse_Sq test...\n");
	{
		printf("L = ");
		ListTraverse_Sq(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("5\nFunction ListLength_Sq test...\n");
	{
		i = ListLength_Sq(L);
		printf("the length of L is %d", i);
		printf("\n");
	}
	PressEnter;

	printf("11\nFunction ListDelete_Sq test...\n");
	{
		ListDelete_Sq(&L, 6, &e);
		printf("delete the 6th data: %d\n", e);
		printf("the data in L is L = ");
		ListTraverse_Sq(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("6\nFunction GetElem_Sq test...\n");
	{
		GetElem_Sq(L, 4, &e);
		printf("the 4th data in L is %d", e);
		printf("\n");
	}
	PressEnter;

	printf("7\nFunction LocateElem_Sq test...\n");
	{
		i = LocateElem_Sq(L, 7, CmpGreater);
		printf("the data larger than 7 in L is %d\n", i);
		printf("\n");
	}
	PressEnter;

	printf("8\nFunction PriorElem_Sq test...\n");
	{
		PriorElem_Sq(L, 6, &e);
		printf("6 de qian qu wei %d\n", e);
		printf("\n");
	}
	PressEnter;

	printf("9\nFunction NextElem_Sq test...\n");
	{
		NextElem_Sq(L, 6, &e);
		printf("6 de hou ji  wei %d\n", e);
		printf("\n");
	}
	PressEnter;

	printf("2\nFunction ClearList_Sq test...\n");
	{
		printf("before clear: ");
		ListEmpty_Sq(L) ? printf("L is empty\n") : printf("L is not empty\n");
		ClearList_Sq(&L);
		printf("after clear: ");
		ListEmpty_Sq(L) ? printf("L is empty\n") : printf("L is not empty\n");
		printf("\n");
	}
	PressEnter;

	printf("3\nFunction DestroyList_Sq test...\n");
	{
		printf("before destroy: ");
		L.elem ? printf("L is alive\n") : printf("L is dead\n");
		DestroyList_Sq(&L);
		printf("after destroy: ");
		L.elem ? printf("L is alive\n") : printf("L is dead\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

