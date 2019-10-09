#include "LlistDef.h"

/* 初始化 */
List makeEmpty()
{
    Position L = (Position)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
/* 查找 */
Position Find( List L, ElementType X )
{
    Position p = L; /* p指向L的第1个结点 */
    while ( p && p->Data!=X )
        p = p->Next;
    return p;
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
	List p=L;
	int j;
	//寻找第i个结点
	for(j = 0;p && j != i;j++)
		p=p->Next;
	if(j != i)
		return false;
	return Insert(L,X,p);
}
 
/* 带头结点的删除 */
int Delete( List L, Position P )
{ /* 这里默认L有头结点 */
    Position tmp, pre;
 
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

/* 带头结点的打印 */
void Print_L( List L )
{
	L = L->Next;
	while(L)
	{
		printf("%d ",L->Data);
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

/* 集合合并 */
void UnionList_L(List La, List Lb)
{
	List p;
	List last = La->Next;
	while(last->Next)
		last = last->Next;
	Lb = Lb->Next;
    while(Lb != NULL)
	{
		for(p = La->Next;p && p->Data != Lb->Data;p = p->Next);
		
		if(!p)
		{
			last->Next = Lb;
			Lb = Lb->Next;
			last = last->Next;
			last->Next = NULL;
		}
		else
			Lb = Lb->Next;
	}
	if(Lb == NULL) printf("ok\n");
}