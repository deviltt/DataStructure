#ifndef CONVERSION_C
#define CONVERSION_C

#include <stdlib.h>
#include <stdio.h>
#include "Conversion.h"

void conversion(int i)
{
	SqStack S;
	SElemType_Sq e;	

	InitStack_Sq(&S);

	while(i){
		Push_Sq(&S, i % 8);
		i /= 8;
	}

	while(!StackEmpty_Sq(S)){
		Pop_Sq(&S, &e);
		printf("%d", e);
	}
}

#endif
