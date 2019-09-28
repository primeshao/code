#include "SqlistDef.h"

//(1)��ʼ�����Ա�
int InitList(SqList * L)
{
	L->elem = (ElemType *)malloc(LIST_Init_Size * sizeof(ElemType));
	if(!L->elem)
		return 0;	//����ʧ���򷵻�0
	L->length = 0;
	L->listsize = LIST_Init_Size;
	return 1;

}

//(2)�������Ա�
void DestroyList(SqList *L)
{	//��free()�ͷ�malloc�Ŀռ䣬���������ı�����ʼ��
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
	printf("Destroyed successful!\n");
}

//(3)�ж��Ƿ�Ϊ�ձ�
int ListEmpty(SqList L)
{
	return (L.length == 0?1:0);
}

//(4)�����Ա�ĳ���
int ListLength(SqList L)
{
	return L.length;
}

//(5)������Ա�
void DispList(SqList L)
{
	int i;
	for(i = 0;i<ListLength(L);i++)
	{
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

//(6.1)��ĳ������Ԫ��ֵ 
int GetElem1(SqList L, int i)
{
	return L.elem[i-1];
}

//(6.2)��ĳ������Ԫ��ֵ
void GetElem2(SqList L, int i,ElemType *e)
{
	*e = L.elem[i-1];
}

//(7)��Ԫ��ֵ���� 
int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i = 0;i<L.length;i++)
	{
		if(L.elem[i] == e)
			return i+1;
	}
	return 0;//δ�ҵ�����0
}

//(8.1)��������Ԫ��
int ListInsert(SqList *L,int i,ElemType e)
{
	int j;
	if(L->length == L->listsize)
	{
		printf("List full!\n");
		return 0;//��������0
	}
	if (i < 0 || i >= L->listsize)
	{
		printf("The wrong location\n");
		return 0;//λ�ô��󷵻�0
	}
	//�������κ�Ų
	for(j = L->length-1;j>=i;j--)
		L->elem[j+1] = L->elem[j];
	L->elem[i] = e;
	L->length++;
	printf("%d has been successfully inserted!\n",e);
	return 1;
}

//(8.2)��������Ԫ��
int Insert(SqList *L, ElemType x)
{
	int i;
	if(L->length == L->listsize)
	{
		printf("List full!\n");
		return 0;//��������0
	}
	//�������κ�Ų
	for(i = L->length - 1;L->elem[i] > x && i >= 0;i--)
		L->elem[i+1] = L->elem[i];
	L->elem[i+1] = x;
	L->length++;
	printf("%d has been successfully inserted!\n",x);
	return 1;
}

//(9)���������Ĺ鲢
void MergeList(SqList La, SqList Lb, SqList *Lc)
{
	int i, j, k;
	int La_len, Lb_len;
	ElemType ai, bj;
	InitList(Lc); // ����յ����Ա� Lc
	i = j = 1;
	k = 0;
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	while ((i <= La_len) && (j <= Lb_len)) // La �� Lb ������
	{
		GetElem2(La, i, &ai);
		GetElem2(Lb, j, &bj);
		if (ai <= bj) 
		{ // �� ai ���뵽 Lc ��
			ListInsert(Lc, k++, ai); 
			i ++;
		}
		else 
		{ // �� bj ���뵽 Lc ��
			ListInsert(Lc, k++, bj); 
			j ++;
		}
	}
	while (i<=La_len) //�� La ����, ���� La ��ʣ�������Ԫ��
	{
		GetElem2(La, i++, &ai);
		ListInsert(Lc, k++, ai);
	}
	while (j<=Lb_len) //�� Lb ����, ���� Lb ��ʣ�������Ԫ��
	{
		GetElem2(Lb, j++, &bj);
		ListInsert(Lc, k++, bj);
	}
}
