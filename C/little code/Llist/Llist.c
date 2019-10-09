#include "LlistDef.h"

/* ��ʼ�� */
List makeEmpty()
{
    Position L = (Position)malloc(sizeof(struct LNode));
    L->Next = NULL;
    return L;
}
/* ���� */
Position Find( List L, ElementType X )
{
    Position p = L; /* pָ��L�ĵ�1����� */
    while ( p && p->Data!=X )
        p = p->Next;
    return p;
}

/* ��ͷ���Ĳ��� */
int Insert( List L, ElementType X, Position P )
{ /* ����Ĭ��L��ͷ��� */
    Position tmp, pre;
 
    /* ����P��ǰһ����� */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next );            
    if ( pre==NULL ) { /* P��ָ�Ľ�㲻��L�� */
        printf("����λ�ò�������\n");
        return false;
    }
    else { /* �ҵ���P��ǰһ�����pre */
        /* ��Pǰ�����½�� */
        tmp = (Position)malloc(sizeof(struct LNode)); /* ���롢��װ��� */
        tmp->Data = X; 
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

/* ��λ����Ų��� */
int ListInsert_L( List L,int i,ElementType X)
{
	List p=L;
	int j;
	//Ѱ�ҵ�i�����
	for(j = 0;p && j != i;j++)
		p=p->Next;
	if(j != i)
		return false;
	return Insert(L,X,p);
}
 
/* ��ͷ����ɾ�� */
int Delete( List L, Position P )
{ /* ����Ĭ��L��ͷ��� */
    Position tmp, pre;
 
    /* ����P��ǰһ����� */        
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;            
    if ( pre==NULL || P==NULL) { /* P��ָ�Ľ�㲻��L�� */
        printf("ɾ��λ�ò�������\n");
        return false;
    }
    else { /* �ҵ���P��ǰһ�����pre */
        /* ��Pλ�õĽ��ɾ�� */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}

/* ��ͷ���Ĵ�ӡ */
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

/* ��ͷ���ĳ��� */
int Length_L( List L )
{
	int length;
	L = L->Next;
	for(length = 0;L;length++)
		L = L->Next;
	return length;
}

/* ���Ϻϲ� */
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