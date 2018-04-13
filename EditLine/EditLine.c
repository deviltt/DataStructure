#include <stdio.h>
#include <stdlib.h>

#define Stack_Init_Size 100
#define Stack_Increment 10

typedef struct{
	char *base;
	char *top;
	int stacksize;
}Stack_Node;

void Print(char e)
{
	printf("%c", e);
}

void InitStack(Stack_Node *L)
{
	L->base = (char *)malloc(Stack_Init_Size * sizeof(char));
	
	if(!(L->base))
		exit(1);
	
	L->top  = L->base;
	L->stacksize = Stack_Init_Size;
}

void Push_St(Stack_Node *L, char buf)
{
	if(L->top - L->base >= L->stacksize){
		L->base = (char *)realloc(L->base, (L->stacksize + Stack_Increment) * sizeof(char));
		
		if(!L->base)
			exit(1);

		L->top = L->base + L->stacksize;		//原因：使用realloc後如果內存不夠可能開闢新的地址空間，這樣 L.base 也會改變，所以可以稱作重定位
		L->stacksize += Stack_Increment;
	}

	*(L->top++) = buf;
}

void Pop_St(Stack_Node *L, char *buf)
{
	if(L->top == L->base)
		exit(1);

	L->top--;	
	*buf = *(L->top);
}

void Clear_St(Stack_Node *L)
{
	L->top = L->base;
}

void St_Traverse(Stack_Node *L, void (Visit)(char))
{
	char *p = L->base;

	while(p < L->top)
		Visit(*(p++));
}

void Destroy_St(Stack_Node *L)
{
	free(L->base);

	L->base = NULL;
	L->top  = NULL;
	L->stacksize = 0;
}

void EditLine(Stack_Node *L, char buff[])
{
	int i = 0;
	char buf, e;

	buf = buff[i++];

	InitStack(L);

	while(buf != '\0'){
		while(buf != '\0' && buf != '\n'){
			switch(buf){
				case '#' : Pop_St(L, &e);
					break;
				case '@' : Clear_St(L);
					break;
				default  : Push_St(L, buf);
			}
			buf = buff[i++];
		}
		if(buf == '\n'){
			Push_St(L, buf);
			St_Traverse(L, Print);
			Clear_St(L);
			buf = buff[i++];
		}
	}

	if(buf == '\0'){
		St_Traverse(L, Print);
		Destroy_St(L);
	}
}

int main()
{
	
	Stack_Node S;
	char *buf = "whli##ile(ture###rue)\n{pir##rint \n\0;}";

	EditLine(&S, buf);

	printf("\n");

	return 0;
}
