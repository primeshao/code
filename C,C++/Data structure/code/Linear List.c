typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;


/* 按值查找 */ 
Position Find( ElementType X, List L )
{
    Position p = L; /* p指向L的第1个结点 */
 
    while ( p && p->Data!=X )
        p = p->Next;

	return p;
}


/* 按序号查找 */ 
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
	/* 找到第K个，返回指针 */
	else return NULL;
	/* 否则返回空 */
}


/* 不带头结点的插入 */
List Insert( ElementType X, int i, List PtrL )
{ 
	List p, s;
	if ( i == 1 ) 
	{ 
		/* 新结点插入在表头 */
		s = (List)malloc(sizeof(struct LNode)); /*申请、填装结点*/
		s->Data = X;
		s->Next = PtrL;
		return s; /*返回新表头指针*/
	}
	p = FindKth( i-1, PtrL ); /* 查找第i-1个结点 */
	if ( p == NULL ) 
	{ 
		/* 第i-1个不存在，不能插入 */
		printf(＂参数i错＂);
		return NULL;
	}
	else 
	{
		s = (List)malloc(sizeof(struct LNode)); /*申请、填装结点*/
		s->Data = X;
		s->Next = p->Next; /*新结点插入在第i-1个结点的后面*/
		p->Next = s;
		return PtrL;
	}
} 


/* 不带头结点的删除 */
List Delete( int i, List PtrL )
{ 
	List p, s;
	if ( i == 1 ) 
	{
		/* 若要删除的是表的第一个结点 */
		s = PtrL; /*s指向第1个结点*/

		if (PtrL!=NULL) PtrL = PtrL->Next; /*从链表中删除*/
		else return NULL;

		free(s); /*释放被删除结点 */

		return PtrL;
	}

	p = FindKth( i-1, PtrL ); /*查找第i-1个结点*/
	if ( p == NULL ) 
	{
		printf(“第%d个结点不存在”, i-1); 
		return NULL;
	} 
	else if ( p->Next == NULL )
	{
		printf(“第%d个结点不存在”, i); 
		return NULL;
	} 
	else {
		s = p->Next; /*s指向第i个结点*/
		p->Next = s->Next; /*从链表中删除*/
		free(s); /*释放被删除结点 */
		return PtrL;
	}
}


/* 求表长 */
int Length ( List PtrL )
{ 
	Position p = PtrL; /* p指向表的第一个结点*/
	int j = 0;
	while ( p ) {
	p = p->Next;
	j++; /* 当前p指向的是第 j 个结点*/
	}
	return j;
}
