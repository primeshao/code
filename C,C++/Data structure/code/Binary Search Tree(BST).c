typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode{ /* 树结点定义 */
    ElementType Data; /* 结点数据 */
    BinTree Left;     /* 指向左子树 */
    BinTree Right;    /* 指向右子树 */
};


/* (伪)递归查找 */
Position Find( ElementType X, BinTree BST )
{
	if( !BST ) return NULL; /*查找失败*/
	if( X > BST->Data )
		return Find( X, BST->Right ); /*在右子树中继续查找*/
	else if( X < BST->Data )
		return Find( X, BST->Left ); /*在左子树中继续查找*/
	else /* X == BST->Data */
		return BST; /*查找成功，返回结点的找到结点的地址*/
}


/* 非递归查找 */
Position IterFind( ElementType X, BinTree BST )
{
	while( BST ) 
	{
		if( X > BST->Data )
			BST = BST->Right; /*向右子树中移动，继续查找*/
		else if( X < BST->Data )
			BST = BST->Left; /*向左子树中移动，继续查找*/
		else /* X == BST->Data */
			return BST; /*查找成功，返回结点的找到结点的地址*/
	}
	return NULL; /*查找失败*/
}


/* 查找最小元素 */
//最小元素一定是在树的最左分枝的端结点上
Position FindMin( BinTree BST )
{
	if( !BST ) return NULL; /*空的二叉搜索树，返回NULL*/
	else if( !BST->Left )
		return BST; /*找到最左叶结点并返回*/
	else
		return FindMin( BST->Left ); /*沿左分支继续查找*/
}


/* 查找最大元素 */
//最大元素一定是在树的最右分枝的端结点上
Position FindMax( BinTree BST )
{
	if(BST)
	{
		while( BST->Right ) BST = BST->Right;
	}
		/*沿右分支继续查找，直到最右叶结点*/
	return BST;
}


/* 插入 */
BinTree Insert( BinTree BST, ElementType X )
{
	//若原树(或结点)为空，生成并返回一个结点的二叉搜索树
    if( !BST ){ 
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* 开始找要插入元素的位置 */
        if( X < BST->Data )
            BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
        else if( X > BST->Data )
            BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
        else;/* X已经存在，什么都不做(该行可全部删除) */
    }
    return BST;
}


/* 删除 */
//要删除的结点只有一个孩子结点: 将其父结点的指针指向要删除结点的孩子结点
//要删除的结点有左、右两棵子树: 用另一结点替代被删除结点(右子树的最小元素 或者 左子树的最大元素)
BinTree Delete( BinTree BST, ElementType X ) 
{ 
    Position Tmp; 
 
    if( !BST ) 
        printf("要删除的元素未找到"); 
    else {
        if( X < BST->Data ) 
            BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
        else if( X > BST->Data ) 
            BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
        else { /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */ 
            if( BST->Left && BST->Right ) {
                /* 从右子树中找最小的元素填充删除结点 */
                Tmp = FindMin( BST->Right );
                BST->Data = Tmp->Data;
                /* 从右子树中删除最小元素 */
                BST->Right = Delete( BST->Right, BST->Data );
            }
            else { /* 被删除结点有一个或无子结点 */
                Tmp = BST; 
                if( !BST->Left )       /* 只有右孩子或无子结点 */
                    BST = BST->Right; 
                else                   /* 只有左孩子 */
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
}