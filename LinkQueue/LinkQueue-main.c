#include <stdio.h>
#include "LinkQueue.c"

void PrintElem(QElemType_L e);

int main()
{
	LinkQueue Q;
	int i;
	QElemType_L e;

	printf("1\n 函数 InitQueue_L 测试... \n");
	{
		printf("初始化链队 Q ...\n");
		InitQueue_L(&Q);
		printf("\n");
	}
	PressEnter;

	printf("4\n 函数 QueueEmpty_L 测试... \n");
	{
		QueueEmpty_L(Q) ? printf(" Q is empty!!!\n") : printf(" Q is not empty!!!\n");
		printf("\n");
	}
	PressEnter;

	printf("7\n 函数 EnQueue_L 测试... \n");
	{
		for(i=1; i<=6; i++){
			printf("元素 \"%d\" 入队，", 2*i);
			EnQueue_L(&Q, 2*i);
			printf("(累计第 %d 个元素)...\n", QueueLength_L(Q));
		}
		printf("\n");
	}
	PressEnter;

	printf("8\n 函数 DeQueue_L 测试... \n");
	{
		DeQueue_L(&Q, &e);
		printf("队头元素 \"%d\" 出队...\n", e);
		printf(" Q 中的元素为：Q = ");
		QueueTraverse_L(Q, PrintElem);
		printf("\n");
	}
	PressEnter;

	printf("5\n 函数 QueueLength_L 测试... \n");
	{
		i = QueueLength_L(Q);
		printf(" Q 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("6\n 函数 GetHead_L 测试... \n");
	{
		GetHead_L(Q, &e);
		printf("队头元素的值为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("3\n 函数 ClearQueue_L 测试... \n");
	{
		printf("清空 Q 前: ");
		QueueEmpty_L(Q) ? printf(" Q 为空!!\n") : printf(" Q 不为空!!\n");
		ClearQueue_L(&Q);
		printf("清空Q后：");
		QueueEmpty_L(Q) ? printf(" Q 为空!!\n") : printf(" Q 不为空!!\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

void PrintElem(QElemType_L e)
{
	printf("%d ", e);
}
