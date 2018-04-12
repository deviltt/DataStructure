#include <stdio.h>
#include "SequenceStack.c"

void PrintElem(SElemType_Sq e);

int main()
{
	SqStack S;
	int i;
	SElemType_Sq e;

	printf("1\n函數 InitStack 測試...\n");{
		printf("初始化順序棧 S...\n");
		InitStack_Sq(&S);
		printf("\n");
	}
	PressEnter;

	printf("4\n函數 StackEmpty 測試...\n");{
		StackEmpty_Sq(S) ? printf("S is empty\n") : printf("S is not empty\n");
	printf("\n");
	}
	PressEnter;

	printf("7\n函數 Push 測試...\n");{
		for(i=1; i<=6; i++){
			printf("將 \"%2d\" 壓入棧 S ", 2*i);
			Push_Sq(&S, 2*i);
			printf("(累計第 %d 個元素)...\n", S.top - S.base);
		}

		printf("\n");
	}
	PressEnter;

	printf("9\n函數 StackTraverse 測試...\n");{
		printf(" S 中的元素爲: S = ");
		StackTraverse_Sq(S, PrintElem);
		printf("\n");
	}
	PressEnter;

	printf("8\n函數 Pop 測試...\n");{
		Pop_Sq(&S, &e);
		printf("棧頂元素 \"%d\" 出棧...\n", e);
		printf(" S 中的元素爲: S = ");
		StackTraverse_Sq(S, PrintElem);
		printf("\n");
	}
	PressEnter;

	printf("5\n函數 StackLength 測試...\n");{
		i = StackLength_Sq(S);
		printf(" S 的長度爲 %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("6\n函數 GetTop 測試...\n");{
		GetTop_Sq(S,  &e);
		printf("棧頂元素的值爲 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("3\n函數 ClearStack 測試...\n");{
		printf("清空 S 前: ");
		StackEmpty_Sq(S) ? printf(" S 爲空！！ \n") : printf(" S 不爲空！！ \n");
		ClearStack_Sq(&S);
		printf("清空 S 後: ");
		StackEmpty_Sq(S) ? printf(" S 爲空！！ \n") : printf(" S 不爲空！！ \n");
		printf("\n");
	}
	PressEnter;

	printf("2\n函數 DestroyStack 測試...\n");{
		printf("銷毀 S 前: ");
		S.base != NULL && S.top != NULL ? printf(" S 存在！\n") : printf(" S 不存在！\n");
		DestroyStack_Sq(&S);
		printf("銷毀 S 後: ");
		S.base != NULL && S.top != NULL ? printf(" S 存在！\n") : printf(" S 不存在！\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

void PrintElem(SElemType_Sq e)
{
	printf("%d ", e);
}
