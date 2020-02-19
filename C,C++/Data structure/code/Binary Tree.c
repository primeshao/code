typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};


/* 中序遍历 */
void InorderTraversal( BinTree BT )
{
    if( BT ) 
	{
        InorderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}


/* 先序遍历 */ 
void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}


/* 后序遍历 */ 
void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}


/* 利用堆栈实现非递归遍历 */ 

/* 非递归中序 */
void InOrderTraversal( BinTree BT )
{ 
	BinTree T=BT;
	Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
	while( T || !IsEmpty(S) )
	{
		while(T)
		{ /*一直向左并将沿途结点压入堆栈*/
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S); /*结点弹出堆栈*/
			printf("%5d", T->Data); /*（访问）打印结点*/
			T = T->Right; /*转向右子树*/
		}
	}
}
 

/* 非递归先序 */
void PreorderTraversal( BinTree BT )
{ 
	BinTree T=BT;
	Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
	while( T || !IsEmpty(S) )
	{
		while(T)
		{ /*一直向左并将沿途结点压入堆栈*/
			printf("%5d", T->Data); /*（访问）打印结点*/
			Push(S,T);
			T = T->Left;
		}
		if(!IsEmpty(S))
		{
			T = Pop(S); /*结点弹出堆栈*/
			T = T->Right; /*转向右子树*/
		}
	}
}


/*非递归后序*/
void PostorderTraversal( BinTree BT ) {}

/* 层序遍历（利用队列） */
void LevelorderTraversal ( BinTree BT )
{ 
    Queue Q; 
    BinTree T;
 
    if ( !BT ) return; /* 若是空树则直接返回 */
     
    Q = CreatQ(); /* 创建空队列Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}


/* 求二叉树的高度 */
int PostOrderGetHeight( BinTree BT )
{ 
	int HL, HR, MaxH;
	if( BT ) 
	{
		HL = PostOrderGetHeight(BT->Left); /*求左子树的深度*/
		HR = PostOrderGetHeight(BT->Right); /*求右子树的深度*/
		MaxH = （HL > HR）? HL : HR; /*取左右子树较大的深度*/
		return ( MaxH + 1 ); /*返回树的深度*/
	}
	else return 0; /* 空树深度为0 */
}

