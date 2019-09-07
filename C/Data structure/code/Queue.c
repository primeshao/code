typedef struct Node *PtrToNode;
struct Node { 
	/* �����еĽ�� */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
 
struct QNode {
    Position Front, Rear;  /* ���е�ͷ��βָ�� */
    //int MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;


/* �ж϶����Ƿ�Ϊ�� */ 
bool IsEmpty( Queue Q )
{
    return ( Q->Front == NULL);
}


/* �������� */
Queue CreatQ()
{
	Queue Q;
	Q->Front = Q->Rear = NULL;
	return Q;
}


/* ����� */
void AddQ( Queue Q,ElementType Data )
{
	Position N;
	N = (Position)malloc(sizeof(struct Node));
	N->Data = Data;
	N->Next = NULL;
	if  ( IsEmpty(Q) ) 
	{
		Q->Front = Q->Rear = N;
		return Q;
    }
	else 
	{
		Q->Rear->Next = N;
		Q->Rear = N;
		return Q;
	}
}


/* ������ */ 
ElementType DeleteQ( Queue Q )
{
    Position FrontCell; 
    ElementType FrontElem;
     
    if  ( IsEmpty(Q) ) 
	{
        printf("���п�");
        return ERROR;
    }
    else 
	{
        FrontCell = Q->Front;
        if ( Q->Front == Q->Rear ) /* ������ֻ��һ��Ԫ�� */
            Q->Front = Q->Rear = NULL; /* ɾ���������Ϊ�� */
        else                     
            Q->Front = FrontCell->Next;
        FrontElem = FrontCell->Data;
 
        free( FrontCell );  /* �ͷű�ɾ�����ռ�  */
        return  FrontElem;
    }
}