#include "CommonDef.h"

struct LNode 
{
    ElementType Data;
    PtrToLNode Next;
};
/* ��ʼ�� */
List makeEmpty();

/* ���� */
Position Find( List L, ElementType X );

/* ��ͷ���Ĳ��� */
int Insert( List L, ElementType X, Position P );

/* ��λ����Ų��� */
int ListInsert_L( List L,int i,ElementType X);

/* ��ͷ����ɾ�� */
int Delete( List L, Position P );

/* ��ͷ���Ĵ�ӡ */
void Print_L( List L );

/* ��ͷ���ĳ��� */
int Length_L( List L );

/* ���Ϻϲ� */
void UnionList_L(List La, List Lb);

