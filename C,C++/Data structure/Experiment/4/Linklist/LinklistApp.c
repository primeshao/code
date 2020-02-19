#include "LinklistDef.h"

/* 初始化 */
List makeEmpty()
{
    Position L = (Position)malloc(sizeof(struct LNode));
    L->Next = NULL;
	printf("初始化完成!\n");
    return L;
}

/* 判定是否为空表 */
int isEmpty( List L )
{
	if(L->Next)
		return false;
	else
		return true;
}


/* 按位置序号查找 */
int Find_L( List L, int i, ElementType * X)
{
	int j;
	//寻找第i个结点
	for(j = 0;L && j != i;j++)
		L = L->Next;
	if(j != i)
		return false;
	else
	{
		*X = L->Data;
	}
		return true;
}

/* 按元素值查找 */
int LocateElem( List L,ElementType X)
{	//找到返回其位置，未找到返回0;
	int i;
	L = L->Next;
	for(i = 1; L && L->Data != X ;i++, L = L->Next);
	if(!L)
		return false;
	else
		return i;
}

/* 带头结点的插入 */
int Insert( List L, ElementType X, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;
 
    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next );            
    if ( pre==NULL ) { /* P所指的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

/* 按位置序号插入 */
int ListInsert_L( List L,int i,ElementType X)
{
	Position p=L;
	int j;
	//寻找第i个结点
	for(j = 0;p && j != i;j++)
		p=p->Next;
	if(j != i)
		return false;
	return Insert(L,X,p);
}

/* 头插法依次插入 */
int Insert_L( List L )
{
	int temp;
	Position p;
	int i,n;
	ifInt = 1;
	printf("你想插入多少元素? ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p = (Position)malloc(sizeof(struct LNode));
		printf("元素 %d: ",i+1);
        scanf("%d",&temp);
		p->Data = (char)temp;
        p->Next = L->Next;//p指向下一个 
        L->Next = p;//再将p给单链表L的表头
	}
	return true;
}

/* 尾插法依次插入 */
int Insert_Tail( List L )
{
	int i,n;
	Position p;
	while(L->Next)
		L = L->Next;
	ifInt = 0;
	printf("你想插入多少元素? ");
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		getchar();
        p = (Position)malloc(sizeof(struct LNode));
		printf("元素 %d: ",i+1);
        scanf("%c",&(p->Data));
        L->Next = p;
        L = p; 
    }
	L->Next = NULL;
	return true;
}
 
/* 带头结点的删除 */
int Delete( List L, Position P )
{ /* 这里默认L有头结点 */
    Position pre;
 
    /* 查找P的前一个结点 */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
    if ( pre==NULL || P==NULL) { /* P所指的结点不在L中 */
        printf("删除位置参数错误\n");
        return false;
    }
    else { /* 找到了P的前一个结点pre */
        /* 将P位置的结点删除 */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}

/* 按位置序号删除 */
int ListDelete(List L,int i,ElementType * e)
{
	Position p=L;
	int j;
	if(i > Length_L(L) || i < 0)
		return false;
	//寻找第i个结点
	for(j = 0;j != i;j++)
		p=p->Next;
	*e = p->Data;
	return Delete(L,p);
}

/* 带头结点的打印 */
void Print_L( List L )
{
	L = L->Next;
	while(L)
	{
		if(!ifInt)
			printf("%c ",L->Data);
		else
			printf("%d ",(int)L->Data);
		L = L->Next;
	}
	printf("\n");
}

/* 带头结点的长度 */
int Length_L( List L )
{
	int length;
	L = L->Next;
	for(length = 0;L;length++)
		L = L->Next;
	return length;
}

/* 销毁带头节点的链表 */
int DestoryList_L( List * L )
{	//连同头结点一并销毁
	Position pre = (*L);
	Position p = (*L)->Next;
	for(;p;p = p->Next)
	{
		free(pre);
		pre = p;
	}
	free(pre);
	*L = NULL;
	return true;
}

/* 带头结点的排序 */
int Sort_L( List L )
{
	Position head, prep1, p1, prep2, p2, premin, min, temp;
    if((L->Next == NULL) || (L->Next->Next == NULL))
		return false;
    head = L;
    for(prep1 = head, p1 = prep1->Next; p1->Next != NULL; prep1 = prep1->Next, p1 = prep1->Next)
    {
        //保存最小节点
        premin = prep1;
        min = p1;
        for(prep2 = p1, p2 = prep2->Next; p2 != NULL; prep2 = prep2->Next, p2 = prep2->Next)
        {
            if(min->Data > p2->Data)
            {
                premin = prep2;
                min = p2;
            }
        }

        if(p1 != min)
        {
            if(p1->Next == min)
            {
                temp = min->Next;
                prep1->Next = min;
                min->Next = p1;
                p1->Next = temp;
            }else{
                temp = min->Next;
                prep1->Next = min;
                min->Next = p1->Next;
                premin->Next = p1;
                p1->Next = temp;
            }
        }
    }
	return true;
}
