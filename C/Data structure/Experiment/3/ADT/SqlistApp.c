#include "SqlistDef.h"

//(1)初始化线性表
int InitList(SqList * L)
{
	L->elem = (ElemType *)malloc(LIST_Init_Size * sizeof(ElemType));
	if(!L->elem)
		return 0;	//创建失败则返回0
	L->length = 0;
	L->listsize = LIST_Init_Size;
	return 1;

}

//(2)销毁线性表
void DestroyList(SqList *L)
{	//用free()释放malloc的空间，并将声明的变量初始化
	free(L->elem);
	L->length = 0;
	L->listsize = 0;
	printf("Destroyed successful!\n");
}

//(3)判定是否为空表
int ListEmpty(SqList L)
{
	return (L.length == 0?1:0);
}

//(4)求线性表的长度
int ListLength(SqList L)
{
	return L.length;
}

//(5)输出线性表
void DispList(SqList L)
{
	int i;
	for(i = 0;i<ListLength(L);i++)
	{
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

//(6.1)求某个数据元素值 
int GetElem1(SqList L, int i)
{
	return L.elem[i-1];
}

//(6.2)求某个数据元素值
void GetElem2(SqList L, int i,ElemType *e)
{
	*e = L.elem[i-1];
}

//(7)按元素值查找 
int LocateElem(SqList L,ElemType e)
{
	int i;
	for(i = 0;i<L.length;i++)
	{
		if(L.elem[i] == e)
			return i+1;
	}
	return 0;//未找到返回0
}

//(8.1)插入数据元素
int ListInsert(SqList *L,int i,ElemType e)
{
	int j;
	if(L->length == L->listsize)
	{
		printf("List full!\n");
		return 0;//表满返回0
	}
	if (i < 0 || i >= L->listsize)
	{
		printf("The wrong location\n");
		return 0;//位置错误返回0
	}
	//数据依次后挪
	for(j = L->length-1;j>=i;j--)
		L->elem[j+1] = L->elem[j];
	L->elem[i] = e;
	L->length++;
	printf("%d has been successfully inserted!\n",e);
	return 1;
}

//(8.2)插入数据元素
int Insert(SqList *L, ElemType x)
{
	int i;
	if(L->length == L->listsize)
	{
		printf("List full!\n");
		return 0;//表满返回0
	}
	//数据依次后挪
	for(i = L->length - 1;L->elem[i] > x && i >= 0;i--)
		L->elem[i+1] = L->elem[i];
	L->elem[i+1] = x;
	L->length++;
	printf("%d has been successfully inserted!\n",x);
	return 1;
}

//(9)两个有序表的归并
void MergeList(SqList La, SqList Lb, SqList *Lc)
{
	int i, j, k;
	int La_len, Lb_len;
	ElemType ai, bj;
	InitList(Lc); // 构造空的线性表 Lc
	i = j = 1;
	k = 0;
	La_len = ListLength(La);
	Lb_len = ListLength(Lb);
	while ((i <= La_len) && (j <= Lb_len)) // La 和 Lb 均不空
	{
		GetElem2(La, i, &ai);
		GetElem2(Lb, j, &bj);
		if (ai <= bj) 
		{ // 将 ai 插入到 Lc 中
			ListInsert(Lc, k++, ai); 
			i ++;
		}
		else 
		{ // 将 bj 插入到 Lc 中
			ListInsert(Lc, k++, bj); 
			j ++;
		}
	}
	while (i<=La_len) //若 La 不空, 插入 La 中剩余的数据元素
	{
		GetElem2(La, i++, &ai);
		ListInsert(Lc, k++, ai);
	}
	while (j<=Lb_len) //若 Lb 不空, 插入 Lb 中剩余的数据元素
	{
		GetElem2(Lb, j++, &bj);
		ListInsert(Lc, k++, bj);
	}
}
