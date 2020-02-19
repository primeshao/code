typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
    ElementType Data; /* ������� */
    BinTree Left;     /* ָ�������� */
    BinTree Right;    /* ָ�������� */
};


/* ������� */
void InorderTraversal( BinTree BT )
{
    if( BT ) 
	{
        InorderTraversal( BT->Left );
        /* �˴������BT���ķ��ʾ��Ǵ�ӡ���� */
        printf("%d ", BT->Data); /* ��������Ϊ���� */
        InorderTraversal( BT->Right );
    }
}


/* ������� */ 
void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}


/* ������� */ 
void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}


/* ���ö�ջʵ�ַǵݹ���� */ 

/* �ǵݹ����� */
void InOrderTraversal( BinTree BT )
{ 
	BinTree T=BT;
	Stack S = CreatStack( MaxSize ); /*��������ʼ����ջS*/
	while( T || !IsEmpty(S) )
	{
		while(T)
		{ /*һֱ���󲢽���;���ѹ���ջ*/
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S); /*��㵯����ջ*/
			printf("%5d", T->Data); /*�����ʣ���ӡ���*/
			T = T->Right; /*ת��������*/
		}
	}
}
 

/* �ǵݹ����� */
void PreorderTraversal( BinTree BT )
{ 
	BinTree T=BT;
	Stack S = CreatStack( MaxSize ); /*��������ʼ����ջS*/
	while( T || !IsEmpty(S) )
	{
		while(T)
		{ /*һֱ���󲢽���;���ѹ���ջ*/
			printf("%5d", T->Data); /*�����ʣ���ӡ���*/
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S); /*��㵯����ջ*/
			T = T->Right; /*ת��������*/
		}
	}
}


/*�ǵݹ����*/
void PostorderTraversal( BinTree BT ) {}

/* ������������ö��У� */
void LevelorderTraversal ( BinTree BT )
{ 
    Queue Q; 
    BinTree T;
 
    if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */
     
    Q = CreatQ(); /* �����ն���Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* ����ȡ�����еĽ�� */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}


/* ��������ĸ߶� */
int PostOrderGetHeight( BinTree BT )
{ 
	int HL, HR, MaxH;
	if( BT ) 
	{
		HL = PostOrderGetHeight(BT->Left); /*�������������*/
		HR = PostOrderGetHeight(BT->Right); /*�������������*/
		MaxH = ��HL > HR��? HL : HR; /*ȡ���������ϴ�����*/
		return ( MaxH + 1 ); /*�����������*/
	}
	else return 0; /* �������Ϊ0 */
}

