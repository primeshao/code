#include "LinklistDef.h"

/* ��ʼ�� */
List makeEmpty()
{
    Position L = (Position)malloc(sizeof(struct LNode));
    L->Next = NULL;
	printf("��ʼ�����!\n");
    return L;
}

/* �ж��Ƿ�Ϊ�ձ� */
int isEmpty( List L )
{
	if(L->Next)
		return false;
	else
		return true;
}


/* ��λ����Ų��� */
int Find_L( List L, int i, ElementType * X)
{
	int j;
	//Ѱ�ҵ�i�����
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

/* ��Ԫ��ֵ���� */
int LocateElem( List L,ElementType X)
{	//�ҵ�������λ�ã�δ�ҵ�����0;
	int i;
	L = L->Next;
	for(i = 1; L && L->Data != X ;i++, L = L->Next);
	if(!L)
		return false;
	else
		return i;
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
	Position p=L;
	int j;
	//Ѱ�ҵ�i�����
	for(j = 0;p && j != i;j++)
		p=p->Next;
	if(j != i)
		return false;
	return Insert(L,X,p);
}

/* ͷ�巨���β��� */
int Insert_L( List L )
{
	int temp;
	Position p;
	int i,n;
	ifInt = 1;
	printf("����������Ԫ��? ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p = (Position)malloc(sizeof(struct LNode));
		printf("Ԫ�� %d: ",i+1);
        scanf("%d",&temp);
		p->Data = (char)temp;
        p->Next = L->Next;//pָ����һ�� 
        L->Next = p;//�ٽ�p��������L�ı�ͷ
	}
	return true;
}

/* β�巨���β��� */
int Insert_Tail( List L )
{
	int i,n;
	Position p;
	while(L->Next)
		L = L->Next;
	ifInt = 0;
	printf("����������Ԫ��? ");
	scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		getchar();
        p = (Position)malloc(sizeof(struct LNode));
		printf("Ԫ�� %d: ",i+1);
        scanf("%c",&(p->Data));
        L->Next = p;
        L = p; 
    }
	L->Next = NULL;
	return true;
}
 
/* ��ͷ����ɾ�� */
int Delete( List L, Position P )
{ /* ����Ĭ��L��ͷ��� */
    Position pre;
 
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

/* ��λ�����ɾ�� */
int ListDelete(List L,int i,ElementType * e)
{
	Position p=L;
	int j;
	if(i > Length_L(L) || i < 0)
		return false;
	//Ѱ�ҵ�i�����
	for(j = 0;j != i;j++)
		p=p->Next;
	*e = p->Data;
	return Delete(L,p);
}

/* ��ͷ���Ĵ�ӡ */
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

/* ��ͷ���ĳ��� */
int Length_L( List L )
{
	int length;
	L = L->Next;
	for(length = 0;L;length++)
		L = L->Next;
	return length;
}

/* ���ٴ�ͷ�ڵ������ */
int DestoryList_L( List * L )
{	//��ͬͷ���һ������
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

/* ��ͷ�������� */
int Sort_L( List L )
{
	Position head, prep1, p1, prep2, p2, premin, min, temp;
    if((L->Next == NULL) || (L->Next->Next == NULL))
		return false;
    head = L;
    for(prep1 = head, p1 = prep1->Next; p1->Next != NULL; prep1 = prep1->Next, p1 = prep1->Next)
    {
        //������С�ڵ�
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
