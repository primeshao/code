typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;


/* ��ֵ���� */ 
Position Find( ElementType X, List L )
{
    Position p = L; /* pָ��L�ĵ�1����� */
 
    while ( p && p->Data!=X )
        p = p->Next;

	return p;
}


/* ����Ų��� */ 
Position FindKth( int K, List PtrL )
{ 
	Position p = PtrL;
	int i = 1;
	while (p !=NULL && i < K )
	{
		p = p->Next;
		i++;
	}
	if ( i == K ) return p;
	/* �ҵ���K��������ָ�� */
	else return NULL;
	/* ���򷵻ؿ� */
}


/* ����ͷ���Ĳ��� */
List Insert( ElementType X, int i, List PtrL )
{ 
	List p, s;
	if ( i == 1 ) 
	{ 
		/* �½������ڱ�ͷ */
		s = (List)malloc(sizeof(struct LNode)); /*���롢��װ���*/
		s->Data = X;
		s->Next = PtrL;
		return s; /*�����±�ͷָ��*/
	}
	p = FindKth( i-1, PtrL ); /* ���ҵ�i-1����� */
	if ( p == NULL ) 
	{ 
		/* ��i-1�������ڣ����ܲ��� */
		printf(������i��);
		return NULL;
	}
	else 
	{
		s = (List)malloc(sizeof(struct LNode)); /*���롢��װ���*/
		s->Data = X;
		s->Next = p->Next; /*�½������ڵ�i-1�����ĺ���*/
		p->Next = s;
		return PtrL;
	}
} 


/* ����ͷ����ɾ�� */
List Delete( int i, List PtrL )
{ 
	List p, s;
	if ( i == 1 ) 
	{
		/* ��Ҫɾ�����Ǳ�ĵ�һ����� */
		s = PtrL; /*sָ���1�����*/

		if (PtrL!=NULL) PtrL = PtrL->Next; /*��������ɾ��*/
		else return NULL;

		free(s); /*�ͷű�ɾ����� */

		return PtrL;
	}

	p = FindKth( i-1, PtrL ); /*���ҵ�i-1�����*/
	if ( p == NULL ) 
	{
		printf(����%d����㲻���ڡ�, i-1); 
		return NULL;
	} 
	else if ( p->Next == NULL )
	{
		printf(����%d����㲻���ڡ�, i); 
		return NULL;
	} 
	else {
		s = p->Next; /*sָ���i�����*/
		p->Next = s->Next; /*��������ɾ��*/
		free(s); /*�ͷű�ɾ����� */
		return PtrL;
	}
}


/* ��� */
int Length ( List PtrL )
{ 
	Position p = PtrL; /* pָ���ĵ�һ�����*/
	int j = 0;
	while ( p ) {
	p = p->Next;
	j++; /* ��ǰpָ����ǵ� j �����*/
	}
	return j;
}
