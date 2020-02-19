#include "CommonDef.h"

struct LNode 
{
    ElementType Data;
    PtrToLNode Next;
};

/* 初始化 */
List makeEmpty();

/* 判定是否为空表 */
int isEmpty( List L );

/* 按位置序号查找 */
int Find_L( List L, int i, ElementType * X);

/* 按元素值查找 */
int LocateElem( List L,ElementType X);

/* 带头结点的插入 */
int Insert( List L, ElementType X, Position P );

/* 按位置序号插入 */
int ListInsert_L( List L,int i,ElementType X);

/* 头插法依次插入 */
int Insert_L( List L );

/* 尾插法依次插入 */
int Insert_Tail( List L );

/* 带头结点的删除 */
int Delete( List L, Position P );

/* 按位置序号删除 */
int ListDelete(List L,int i,int * e);

/* 带头结点的打印 */
void Print_L( List L );

/* 带头结点的长度 */
int Length_L( List L );

/* 销毁带头节点的链表 */
int DestoryList_L( List * L );

/* 带头结点的排序 */
int Sort_L( List L );

int ifInt;