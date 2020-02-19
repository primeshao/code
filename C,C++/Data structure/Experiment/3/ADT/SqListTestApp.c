#include "SqlistDef.h"
int main()
{
	SqList La, Lb, Lc;
	SqList ADT;
	printf("���ڿ�ʼ���Թ���!\n...\n");
	//���ܲ���(1)
	printf("(1)����˳���L\n");
	if(!InitList(&ADT))
		printf("Failed to establish!\n");
	else
		printf("Successfully established!\n");

	//���ܲ���(2)
	printf("(2)���β�������Ԫ��13,5,27,9,32,123,76,98,54,87\n");
	ListInsert(&ADT,0,13);
	ListInsert(&ADT,1,5);
	ListInsert(&ADT,2,27);
	ListInsert(&ADT,3,9);
	ListInsert(&ADT,4,32);
	ListInsert(&ADT,5,123);
	ListInsert(&ADT,6,76);
	ListInsert(&ADT,7,98);
	ListInsert(&ADT,8,54);
	ListInsert(&ADT,9,87);

	//���ܲ���(3)
	printf("(3)���˳���L\n");
	DispList(ADT);

	//���ܲ���(4)
	printf("(4)���˳���L�ĳ���\n");
	printf("The length of the List is %d.\n",ListLength(ADT));

	//���ܲ���(5)
	printf("(5)�ж�˳���L�Ƿ�Ϊ��\n");
	if(ListEmpty(ADT))
		printf("The List is empty!\n");
	else
		printf("The List is not empty!\n");

	//���ܲ���(6)
	printf("(6)���˳���L�ĵ�3������Ԫ��\n");
	printf("The third number is %d.\n",GetElem1(ADT,3));

	//���ܲ���(7)
	printf("(7)�������Ԫ��76��λ��\n");
	printf("The first position of 76 is %d.\n",LocateElem(ADT,76));

	//���ܲ���(8)
	printf("(8)�ڵ�4��λ���ϲ�������Ԫ��56\n");
	ListInsert(&ADT,4-1,56);

	//���ܲ���(9)
	printf("(9)���˳���L�ĳ���\n");
	printf("The length of the List is %d.\n",ListLength(ADT));

	//���ܲ���(10)
	printf("(10)���˳���L\n");
	DispList(ADT);

	//���ܲ���(11)
	printf("(11)����˳���L\n");
	DestroyList(&ADT);

	//���Ӳ���
	printf("���Ӳ���\n...\n����˳���La,Lb\n");
	if(InitList(&La) && InitList(&Lb))
		printf("Successfully established!\n");
	else
		printf("Failed to establish!\n");
	printf("����Ԫ��\n...\n");
	//�����Ĳ���
	Insert(&La,56);
	Insert(&La,22);
	Insert(&La,69);
	Insert(&La,22);
	Insert(&La,28);
	Insert(&La,12);
	Insert(&La,22);
	Insert(&La,73);
	Insert(&Lb,11);
	Insert(&Lb,32);
	Insert(&Lb,52);
	Insert(&Lb,89);
	Insert(&Lb,29);
	Insert(&Lb,20);
	Insert(&Lb,52);
	Insert(&Lb,12);
	Insert(&Lb,63);
	//������������
	printf("������La: ");
	DispList(La);
	printf("������Lb: ");
	DispList(Lb);
	//�鲢La,Lb
	printf("���ڹ鲢\n...\n");
	MergeList(La, Lb, &Lc);
	//����鲢��ı�Lc
	printf("��ɹ鲢 Lc: ");
	DispList(Lc);
	//����La,Lb,Lc
	printf("��ʼ����\n...\n");
	DestroyList(&La);
	DestroyList(&Lb);
	DestroyList(&Lc);

	return 0;
}