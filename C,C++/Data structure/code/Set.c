#define MAXN 1000                  /* �������Ԫ�ظ��� */
typedef int ElementType;           /* Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ */
typedef int SetName;               /* Ĭ���ø������±���Ϊ�������� */
typedef ElementType Set[MAXN];		/* ���輯��Ԫ���±��0��ʼ */
struct Set{
	ElementType Data;
	int Parent;
	} 

/* ���ϵĲ����� */
void Union( Set S[ ], ElementType X1, ElementType X2 ) 
{ 
    int Root1, Root2; 
    Root1 = Find(S, X1); 
    Root2 = Find(S, X2); 
    if( Root1 != Root2 )
		S[Root2].Parent = Root1; 
}

/* ����ĳ��Ԫ�����ڵļ��ϣ��ø�����ʾ�� */
int Find( Set S[ ], ElementType X ) 
{	/* ������S�в���ֵΪX��Ԫ�������ļ��� */
	/* MaxSize��ȫ�ֱ�����Ϊ����S����󳤶� */ 
	int i; 
	for ( i=0; i < MaxSize && S[i].Data != X; i++) ; 
	if( i >= MaxSize )
		return -1; /* δ�ҵ�X������-1 */ 
	while(s[i].Parent >=0 )
		i = S[i].Parent;  
	return i; /* �ҵ�X�������ϣ������������������S�е��±� */ 
}


/* ����Ĳ�����ʽ�ǽ��±굱������ʹ�� */
void Union( SetType S, SetName Root1, SetName Root2 )
{ 	/* ����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� */
    /* ��֤С���ϲ���󼯺� */
    if ( S[Root2] < S[Root1] ) { /* �������2�Ƚϴ� */
        S[Root2] += S[Root1];     /* ����1���뼯��2  */
        S[Root1] = Root2;
    }
    else {                         /* �������1�Ƚϴ� */
        S[Root1] += S[Root2];     /* ����2���뼯��1  */
        S[Root2] = Root1;
    }
	//Ϊ�˸��ƺϲ��Ժ�Ĳ������ܿ��Բ���С�ļ��Ϻϲ�����Դ�ļ����У��ü���parent�ڵ�ľ���ֵ��ʾ�ü��ϵĴ�С
}

SetName Find( SetType S, ElementType X )
{ /* Ĭ�ϼ���Ԫ��ȫ����ʼ��Ϊ-1 */
    if ( S[X] < 0 ) /* �ҵ����ϵĸ� */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* ·��ѹ�� */
} 