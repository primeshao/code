typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

/* ����һ����ջ��ͷ��㣬���ظý��ָ�� */ 
Stack CreateStack( ) 
{ 
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}


/* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */ 
bool IsEmpty ( Stack S )
{ 
    return ( S->Next == NULL );
}


/* ��Ԫ��Xѹ���ջS */ 
bool Push( Stack S, ElementType X )
{ 
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}


/* ɾ�������ض�ջS��ջ��Ԫ�� */ 
ElementType Pop( Stack S )  
{ 
    PtrToSNode FirstCell;
    ElementType TopElem;
 
    if( IsEmpty(S) ) {
        printf("��ջ��"); 
        return ERROR;
    }
    else {
        FirstCell = S->Next; 
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}