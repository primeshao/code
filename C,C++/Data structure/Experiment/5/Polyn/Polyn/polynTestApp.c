#include "polynDef.h"
int main()
{
	LinkList p1, p2, p3, p4, p5;
	printf("�������ʽ1��ϵ�� ָ����:\n");
	p1=CreatPolyn();
	printf("�������ʽ2��ϵ�� ָ����:\n");
	p2=CreatPolyn();
	printf("\n����ʽ1:\n");
	PrintPolyn(p1);
	printf("\n����ʽ2:\n");
	PrintPolyn(p2);
	printf("\n����ʽ1 + ����ʽ2= \n");
	p3=AddPolyn(p1, p2);
	PrintPolyn(p3);
	printf("\n����ʽ1 - ����ʽ2= \n");
	p4=SubstractPolyn(p1, p2);
	PrintPolyn(p4);
	printf("\n����ʽ1 * ����ʽ2= \n");
	p5=MultiplyPolyn(p1, p2);
	PrintPolyn(p5);
	if(DestroyPolyn(&p1) 
		&& DestroyPolyn(&p2)
		&& DestroyPolyn(&p3) 
		&& DestroyPolyn(&p4)
		&& DestroyPolyn(&p5)
		)
		printf("���ٳɹ���\n");
	return 0;
}