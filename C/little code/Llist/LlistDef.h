#include "CommonDef.h"

struct LNode 
{
    ElementType Data;
    PtrToLNode Next;
};
/* 初始化 */
List makeEmpty();

/* 查找 */
Position Find( List L, ElementType X );

/* 带头结点的插入 */
int Insert( List L, ElementType X, Position P );

/* 按位置序号插入 */
int ListInsert_L( List L,int i,ElementType X);

/* 带头结点的删除 */
int Delete( List L, Position P );

/* 带头结点的打印 */
void Print_L( List L );

/* 带头结点的长度 */
int Length_L( List L );

/* 集合合并 */
void UnionList_L(List La, List Lb);

