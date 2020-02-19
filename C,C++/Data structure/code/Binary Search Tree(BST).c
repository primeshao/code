typedef struct TNode *Position;
typedef Position BinTree; /* ���������� */
struct TNode{ /* ����㶨�� */
    ElementType Data; /* ������� */
    BinTree Left;     /* ָ�������� */
    BinTree Right;    /* ָ�������� */
};


/* (α)�ݹ���� */
Position Find( ElementType X, BinTree BST )
{
	if( !BST ) return NULL; /*����ʧ��*/
	if( X > BST->Data )
		return Find( X, BST->Right ); /*���������м�������*/
	else if( X < BST->Data )
		return Find( X, BST->Left ); /*���������м�������*/
	else /* X == BST->Data */
		return BST; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
}


/* �ǵݹ���� */
Position IterFind( ElementType X, BinTree BST )
{
	while( BST ) 
	{
		if( X > BST->Data )
			BST = BST->Right; /*�����������ƶ�����������*/
		else if( X < BST->Data )
			BST = BST->Left; /*�����������ƶ�����������*/
		else /* X == BST->Data */
			return BST; /*���ҳɹ������ؽ����ҵ����ĵ�ַ*/
	}
	return NULL; /*����ʧ��*/
}


/* ������СԪ�� */
//��СԪ��һ���������������֦�Ķ˽����
Position FindMin( BinTree BST )
{
	if( !BST ) return NULL; /*�յĶ���������������NULL*/
	else if( !BST->Left )
		return BST; /*�ҵ�����Ҷ��㲢����*/
	else
		return FindMin( BST->Left ); /*�����֧��������*/
}


/* �������Ԫ�� */
//���Ԫ��һ�������������ҷ�֦�Ķ˽����
Position FindMax( BinTree BST )
{
	if(BST)
	{
		while( BST->Right ) BST = BST->Right;
	}
		/*���ҷ�֧�������ң�ֱ������Ҷ���*/
	return BST;
}


/* ���� */
BinTree Insert( BinTree BST, ElementType X )
{
	//��ԭ��(����)Ϊ�գ����ɲ�����һ�����Ķ���������
    if( !BST ){ 
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
        if( X < BST->Data )
            BST->Left = Insert( BST->Left, X );   /*�ݹ����������*/
        else if( X > BST->Data )
            BST->Right = Insert( BST->Right, X ); /*�ݹ����������*/
        else;/* X�Ѿ����ڣ�ʲô������(���п�ȫ��ɾ��) */
    }
    return BST;
}


/* ɾ�� */
//Ҫɾ���Ľ��ֻ��һ�����ӽ��: ���丸����ָ��ָ��Ҫɾ�����ĺ��ӽ��
//Ҫɾ���Ľ����������������: ����һ��������ɾ�����(����������СԪ�� ���� �����������Ԫ��)
BinTree Delete( BinTree BST, ElementType X ) 
{ 
    Position Tmp; 
 
    if( !BST ) 
        printf("Ҫɾ����Ԫ��δ�ҵ�"); 
    else {
        if( X < BST->Data ) 
            BST->Left = Delete( BST->Left, X );   /* ���������ݹ�ɾ�� */
        else if( X > BST->Data ) 
            BST->Right = Delete( BST->Right, X ); /* ���������ݹ�ɾ�� */
        else { /* BST����Ҫɾ���Ľ�� */
            /* �����ɾ����������������ӽ�� */ 
            if( BST->Left && BST->Right ) {
                /* ��������������С��Ԫ�����ɾ����� */
                Tmp = FindMin( BST->Right );
                BST->Data = Tmp->Data;
                /* ����������ɾ����СԪ�� */
                BST->Right = Delete( BST->Right, BST->Data );
            }
            else { /* ��ɾ�������һ�������ӽ�� */
                Tmp = BST; 
                if( !BST->Left )       /* ֻ���Һ��ӻ����ӽ�� */
                    BST = BST->Right; 
                else                   /* ֻ������ */
                    BST = BST->Left;
                free( Tmp );
            }
        }
    }
    return BST;
}