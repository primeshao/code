#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType Set[MAXN];		/* 假设集合元素下标从0开始 */
struct Set{
	ElementType Data;
	int Parent;
	} 

/* 集合的并运算 */
void Union( Set S[ ], ElementType X1, ElementType X2 ) 
{ 
    int Root1, Root2; 
    Root1 = Find(S, X1); 
    Root2 = Find(S, X2); 
    if( Root1 != Root2 )
		S[Root2].Parent = Root1; 
}

/* 查找某个元素所在的集合（用根结点表示） */
int Find( Set S[ ], ElementType X ) 
{	/* 在数组S中查找值为X的元素所属的集合 */
	/* MaxSize是全局变量，为数组S的最大长度 */ 
	int i; 
	for ( i=0; i < MaxSize && S[i].Data != X; i++) ; 
	if( i >= MaxSize )
		return -1; /* 未找到X，返回-1 */ 
	while(s[i].Parent >=0 )
		i = S[i].Parent;  
	return i; /* 找到X所属集合，返回树根结点在数组S中的下标 */ 
}


/* 下面的操作方式是将下标当做数据使用 */
void Union( SetType S, SetName Root1, SetName Root2 )
{ 	/* 这里默认Root1和Root2是不同集合的根结点 */
    /* 保证小集合并入大集合 */
    if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
        S[Root2] += S[Root1];     /* 集合1并入集合2  */
        S[Root1] = Root2;
    }
    else {                         /* 如果集合1比较大 */
        S[Root1] += S[Root2];     /* 集合2并入集合1  */
        S[Root2] = Root1;
    }
	//为了改善合并以后的查找性能可以采用小的集合合并到相对大的集合中，用集合parent节点的绝对值表示该集合的大小
}

SetName Find( SetType S, ElementType X )
{ /* 默认集合元素全部初始化为-1 */
    if ( S[X] < 0 ) /* 找到集合的根 */
        return X;
    else
        return S[X] = Find( S, S[X] ); /* 路径压缩 */
} 