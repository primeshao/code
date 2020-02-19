#include "LinklistDef.h"

//����չʾ���ܲ˵�
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
		printf("\n����������ѡ��(��0�˳�): ");
		scanf("%d",&selector);
		system("cls");
		showHelp();
		switch(selector)
		{
			case 0: ifExit = 1;system("cls");break;
			case 1: L = makeEmpty();break;
			case 2: 
				if(isEmpty(L))
					printf("�˱�Ϊ��.\n");
				else
					printf("�˱�ǿ�.\n");
				break;
			case 3:
				if(Insert_Tail(L))
				{
					system("cls");
					showHelp();
					printf("β�����.\n");
				}
				break;
			case 4:
				if(Insert_L(L))
				{
					system("cls");
					showHelp();
					printf("ͷ�����.\n");
				}
				break;
			case 5:
				Print_L(L);break;
			case 6:
				printf("����: %d\n",Length_L(L));break;
			case 7:
				printf("��������ڼ���Ԫ��?\n");
				scanf("%d",&locate);
				if(Find_L(L,locate,&X))
					printf("��%d��Ԫ���� %c.\n",locate,X);
				break;
			case 8:
				printf("��������ĸ�Ԫ�ص�λ��?\n");
				getchar();
				scanf("%c",&X);
				locate = LocateElem(L,X);
				if(locate != 0)
					printf("Ԫ��%c��һ�γ��ֵ�λ���� %d.\n",X,locate);
				else
					printf("δ�ҵ�!\n");
				break;
			case 9:
				printf("�������ĸ�λ�ò���Ԫ��? ");
				scanf("%d",&locate);
				getchar();
				printf("��������Ҫ�����Ԫ��: ");
				scanf("%c",&X);
				if(ListInsert_L(L,locate,X))
					printf("����ɹ�!\n");
				else
					printf("����ʧ��!\n");
				break;
			case 10:
				printf("����ɾ���ĸ�λ�õ�Ԫ��? ");
				scanf("%d",&locate);
				if(ListDelete(L,locate,&X))
					printf("Ԫ�� %c ɾ���ɹ�!\n",X);
				else
					printf("ɾ��ʧ��!\n");
				break;
			case 11:
				if(DestoryList_L(&L))
					printf("������!\n");
				break;
			case 12:
				if(Sort_L(L))
					printf("����ɹ�!\n");
				break;
			default: printf("����������������������0��12������!\n");
		}
	}
	return 0;
}

void showHelp()
{
	printf("********************************************************************\n");
	printf("\t\t\t    ���ܲ˵�\n");
	printf("********************************************************************\n");
	printf("1.��ʼ��������L\t\t\t2.�ж�����L�Ƿ�Ϊ��\n");
	printf("3.β�巨����Ԫ��\t\t4.ͷ�巨����Ԫ��\n");
	printf("5.�������L\t\t\t6.�������L�ĳ���\n");
	printf("7.�������Lĳ��λ�õ�Ԫ��\t8.���ĳ��Ԫ�ص�λ��\n");
	printf("9.��ĳ��λ���ϲ���Ԫ��\t\t10.ɾ������Lĳ��λ�õ�Ԫ��\n");
	printf("11.��������L\t\t\t12.��������L������Ԫ��ֵ��С��������\n");
	printf("********************************************************************\n");
}