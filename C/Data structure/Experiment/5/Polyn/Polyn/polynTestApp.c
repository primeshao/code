#include "polynDef.h"
int main()
{
	LinkList p1, p2, p3, p4, p5;
	printf("输入多项式1（系数 指数）:\n");
	p1=CreatPolyn();
	printf("输入多项式2（系数 指数）:\n");
	p2=CreatPolyn();
	printf("\n多项式1:\n");
	PrintPolyn(p1);
	printf("\n多项式2:\n");
	PrintPolyn(p2);
	printf("\n多项式1 + 多项式2= \n");
	p3=AddPolyn(p1, p2);
	PrintPolyn(p3);
	printf("\n多项式1 - 多项式2= \n");
	p4=SubstractPolyn(p1, p2);
	PrintPolyn(p4);
	printf("\n多项式1 * 多项式2= \n");
	p5=MultiplyPolyn(p1, p2);
	PrintPolyn(p5);
	if(DestroyPolyn(&p1) 
		&& DestroyPolyn(&p2)
		&& DestroyPolyn(&p3) 
		&& DestroyPolyn(&p4)
		&& DestroyPolyn(&p5)
		)
		printf("销毁成功！\n");
	return 0;
}