#include "LinklistDef.h"

//用于展示功能菜单
void showHelp();

int main()
{
	int locate;
	ElementType X;
	List L;
	int ifExit = 0;
	int selector;
	showHelp();
	while(!ifExit)
	{
		printf("\n请输入您的选择(以0退出): ");
		scanf("%d",&selector);
		system("cls");
		showHelp();
		switch(selector)
		{
			case 0: ifExit = 1;system("cls");break;
			case 1: L = makeEmpty();break;
			case 2: 
				if(isEmpty(L))
					printf("此表为空.\n");
				else
					printf("此表非空.\n");
				break;
			case 3:
				if(Insert_Tail(L))
				{
					system("cls");
					showHelp();
					printf("尾插完成.\n");
				}
				break;
			case 4:
				if(Insert_L(L))
				{
					system("cls");
					showHelp();
					printf("头插完成.\n");
				}
				break;
			case 5:
				Print_L(L);break;
			case 6:
				printf("长度: %d\n",Length_L(L));break;
			case 7:
				printf("你想输出第几个元素?\n");
				scanf("%d",&locate);
				if(Find_L(L,locate,&X))
					printf("第%d个元素是 %c.\n",locate,X);
				break;
			case 8:
				printf("你想输出哪个元素的位置?\n");
				getchar();
				scanf("%c",&X);
				locate = LocateElem(L,X);
				if(locate != 0)
					printf("元素%c第一次出现的位置是 %d.\n",X,locate);
				else
					printf("未找到!\n");
				break;
			case 9:
				printf("你想在哪个位置插入元素? ");
				scanf("%d",&locate);
				getchar();
				printf("请输入你要插入的元素: ");
				scanf("%c",&X);
				if(ListInsert_L(L,locate,X))
					printf("插入成功!\n");
				else
					printf("插入失败!\n");
				break;
			case 10:
				printf("你想删除哪个位置的元素? ");
				scanf("%d",&locate);
				if(ListDelete(L,locate,&X))
					printf("元素 %c 删除成功!\n",X);
				else
					printf("删除失败!\n");
				break;
			case 11:
				if(DestoryList_L(&L))
					printf("已销毁!\n");
				break;
			case 12:
				if(Sort_L(L))
					printf("排序成功!\n");
				break;
			default: printf("您的输入有误，请重新输入0到12的数字!\n");
		}
	}
	return 0;
}

void showHelp()
{
	printf("********************************************************************\n");
	printf("\t\t\t    功能菜单\n");
	printf("********************************************************************\n");
	printf("1.初始化单链表L\t\t\t2.判断链表L是否为空\n");
	printf("3.尾插法插入元素\t\t4.头插法插入元素\n");
	printf("5.输出链表L\t\t\t6.输出链表L的长度\n");
	printf("7.输出链表L某个位置的元素\t8.输出某个元素的位置\n");
	printf("9.在某个位置上插入元素\t\t10.删除链表L某个位置的元素\n");
	printf("11.销毁链表L\t\t\t12.将单链表L按数据元素值由小到大排序\n");
	printf("********************************************************************\n");
}