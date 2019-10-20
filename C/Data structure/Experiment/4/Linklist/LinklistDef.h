#include "CommonDef.h"

struct LNode 
{
    ElementType Data;
    PtrToLNode Next;
};

/* ��ʼ�� */
List makeEmpty();

/* �ж��Ƿ�Ϊ�ձ� */
int isEmpty( List L );

/* ��λ����Ų��� */
int Find_L( List L, int i, ElementType * X);

/* ��Ԫ��ֵ���� */
int LocateElem( List L,ElementType X);

/* ��ͷ���Ĳ��� */
int Insert( List L, ElementType X, Position P );

/* ��λ����Ų��� */
int ListInsert_L( List L,int i,ElementType X);

/* ͷ�巨���β��� */
int Insert_L( List L );

/* β�巨���β��� */
int Insert_Tail( List L );

/* ��ͷ����ɾ�� */
int Delete( List L, Position P );

/* ��λ�����ɾ�� */
int ListDelete(List L,int i,int * e);

/* ��ͷ���Ĵ�ӡ */
void Print_L( List L );

/* ��ͷ���ĳ��� */
int Length_L( List L );

/* ���ٴ�ͷ�ڵ������ */
int DestoryList_L( List * L );

/* ��ͷ�������� */
int Sort_L( List L );

int ifInt;