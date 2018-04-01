Status CmpGreater(LElemType_L e, LElemType_L data);
void PrintElem(LElemType_L e);

int main()
{
	LinkList L;
	int i;
	LElemType_L e;

	printf("1\n函数 InitList_L 测试...\n");
	{
		printf("初始化单链表 L...\n");
		InitList_L(&L);
		printf("\n");
	}PressEnter;

	printf("4\n函数 ListEmpty_L 测试...\n");
	{
		ListEmpty_L(L) ? printf("L 为空！！\n") : printf("L 不为空！\n");
		printf("\n");
	}PressEnter;

	printf("10\n函数 ListInsert)L 测试...\n");
	{
		for(i=1; i<=6; i++){
			printf("在 L 第 %d 个位置插入 \"%d\"...\n", i, 2*i);
			ListInsert_L(L, i, 2*i);
		}
		printf("\n");
	}PressEnter;

	printf("12\n 函数 ListTraverse_L 测试...\n");
	{
		printf("L 中的元素为: L = ");
		ListTraverse_L(L, PrintElem);
		printf("\n");
	}PressEnter;

	printf("5\n 函数 ListLength_L 测试...\n");
	{
		printf("L的长度为 %d\n", ListLength_L(L));
		printf("\n");
	}PressEnter;

	printf("11\n 函数 ListDelete_L 测试...\n");
	{
		ListDelete_L(L, 6, &e);
		printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
	}PressEnter;
	
	printf("6\n 函数 GetElem_L 测试...\n");
	{
		GetElem_L(L, 4, &e);
		printf("L 中的第 4 个位置的元素为 \"%d\"\n", e);
		printf("\n");
	}PressEnter;

	printf("8\n 函数PriorElem_L 测试...\n");
	{
		PriorElem_L(L, 6, &e);
		printf("元素 \"6\" 的前驱为 \"%d\" \n", e);
		printf("\n");
	}PressEnter;

	printf("9\n 函数 NextElem_L 测试...\n");
	{
		NextElem_L(L, 6, &e);
		printf("元素 \"6\" 的后继为 \"%d\" \n", e);
		printf("\n");
	}PressEnter;

	{
		
	}PressEnter;
	
	{

	}PressEnter;
	
	{

	}PressEnter;
}
