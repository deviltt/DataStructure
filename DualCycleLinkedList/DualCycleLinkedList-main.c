#include <stdio.h>
#include "DualCycleLinkedList.c"

Status CmpGreater(LElemType_DC e, LElemType_DC data);
void PrintElem(LElemType_DC e);

int main()
{
	DuLinkList L;
	int i;
	LElemType_DC e;

	printf("1\n函数 InitList_DuL 测试...\n");
	{
		printf("初始化双循环链表 L...\n");
		InitList_DuL(&L);
		printf("\n");
	}
	PressEnter;

	printf("4\n函数 ListEmpty_DuL 测试...\n");
	{
		ListEmpty_DuL(L) ? printf("L is empty\n") : printf("L is not empty\n");
	}
	PressEnter;

	printf("11\n函数 ListInsert_DuL 测试...\n");
	{
		for(i=1; i<=6; i++){
			printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert_DuL(L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;

	printf("13\n函数 ListTraverse_DuL 测试...\n");
	{
		printf("L 中的元素为: L = ");
		ListTraverse_DuL(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("5\n函数 ListLength_DuL 测试...\n");
	{
		printf(" L 的长度为 %d \n", ListLength_DuL(L));
		printf("\n");
	}
	PressEnter;

	printf("12\n函数 ListDelete_DuL 测试...\n");
	{
		ListDelete_DuL(L, 6, &e);
		printf("删除 L 中的第6个元素 \"%d\" ...\n", e);
		printf(" L 中的元素为: L = ");
		ListTraverse_DuL(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("6\n函数 GetElem_DuL 测试...\n");
	{
		GetElem_DuL(L, 4, &e);
		printf(" L 中第 4 个位置的元素为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("7\n函数 LocateElem_DuL 测试...\n");
	{
		i = LocateElem_DuL(L, 7, CmpGreater);
		printf(" L 中第一个元素值大于 \"7\" 的元素的位置为 %d \n", i);
		printf("\n");
	}
	PressEnter;

	printf("8\n函数 PriorElem_DuL 测试...\n");
	{
		PriorElem_DuL(L, 6, &e);
		printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("9\n函数 NextElem_DuL 测试...\n");
	{
		NextElem_DuL(L, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;

	printf("10\n函数 GetElem_P 测试...\n");
	{
		DuLinkList p;
		p = GetElemPtr_DuL(L, 3);
		printf("链表第 3 个结点的指针为 0x%x, 其对应的值为 \"%d\" \n", p, p->data);
		printf("\n");
	}
	PressEnter;

	printf("3\n函数 ClearList_DuL 测试...\n");
	{
		printf("清空 L 前: ");
		ListEmpty_DuL(L) ? printf(" L 为空!!\n") : printf(" L 不为空!\n");
		ClearList_DuL(L);
		printf("清空 L 后: ");
		ListEmpty_DuL(L) ? printf(" L 为空!!\n") : printf(" L 不为空!\n");
		printf("\n");
	}
	PressEnter;

	printf("2\n函数 DestroyList_DuL 测试...\n");
	{
		printf("销毁 L 前: ");
		L ? printf(" L 存在! \n") : printf(" L 不存在!!\n");
		DestroyList_DuL(&L);
		printf("销毁 L 后");
		L ? printf(" L 存在! \n") : printf(" L 不存在!!\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

Status CmpGreater(LElemType_DC e, LElemType_DC data)
{
	return data > e ? TRUE : FALSE;
}

void PrintElem(LElemType_DC e)
{
	printf("%d ", e);
}
