#include "SqlistDef.h"
int main()
{
	SqList La, Lb, Lc;
	SqList ADT;
	printf("现在开始测试功能!\n...\n");
	//功能测试(1)
	printf("(1)建立顺序表L\n");
	if(!InitList(&ADT))
		printf("Failed to establish!\n");
	else
		printf("Successfully established!\n");

	//功能测试(2)
	printf("(2)依次插入数据元素13,5,27,9,32,123,76,98,54,87\n");
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

	//功能测试(3)
	printf("(3)输出顺序表L\n");
	DispList(ADT);

	//功能测试(4)
	printf("(4)输出顺序表L的长度\n");
	printf("The length of the List is %d.\n",ListLength(ADT));

	//功能测试(5)
	printf("(5)判断顺序表L是否为空\n");
	if(ListEmpty(ADT))
		printf("The List is empty!\n");
	else
		printf("The List is not empty!\n");

	//功能测试(6)
	printf("(6)输出顺序表L的第3个数据元素\n");
	printf("The third number is %d.\n",GetElem1(ADT,3));

	//功能测试(7)
	printf("(7)输出数据元素76的位置\n");
	printf("The first position of 76 is %d.\n",LocateElem(ADT,76));

	//功能测试(8)
	printf("(8)在第4个位置上插入数据元素56\n");
	ListInsert(&ADT,4-1,56);

	//功能测试(9)
	printf("(9)输出顺序表L的长度\n");
	printf("The length of the List is %d.\n",ListLength(ADT));

	//功能测试(10)
	printf("(10)输出顺序表L\n");
	DispList(ADT);

	//功能测试(11)
	printf("(11)销毁顺序表L\n");
	DestroyList(&ADT);

	//附加测试
	printf("附加测试\n...\n建立顺序表La,Lb\n");
	if(InitList(&La) && InitList(&Lb))
		printf("Successfully established!\n");
	else
		printf("Failed to establish!\n");
	printf("插入元素\n...\n");
	//有序表的插入
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
	//输出两个有序表
	printf("有序表表La: ");
	DispList(La);
	printf("有序表表Lb: ");
	DispList(Lb);
	//归并La,Lb
	printf("正在归并\n...\n");
	MergeList(La, Lb, &Lc);
	//输出归并后的表Lc
	printf("完成归并 Lc: ");
	DispList(Lc);
	//销毁La,Lb,Lc
	printf("开始销毁\n...\n");
	DestroyList(&La);
	DestroyList(&Lb);
	DestroyList(&Lc);

	return 0;
}