#include "CommonDef.h"
//���Ա�洢�ռ�ĳ�ʼ������
typedef struct{
	ElemType *elem;//�洢�������ַ
	int length;//��ǰ��Ч����
	int listsize;//��ǰ����Ĵ洢����
}SqList;

//(1)��ʼ�����Ա�
/* ������Ľ���ǹ���һ���յ����Ա� L��Ϊ���Ա����洢�ռ����ڴ������Ԫ��, �ɹ����� 1 ,����Ϊ 0 */ 
int InitList(SqList *L);

//(2)�������Ա�
/* ������Ľ�����ͷ����Ա� L ռ�õ��ڴ�ռ� */
void DestroyList(SqList *L);

//(3)�ж��Ƿ�Ϊ�ձ�
/* �����㷵��һ��ֵ��ʾ L �Ƿ�Ϊ�ձ��� L Ϊ�ձ�,�򷵻� 1,���򷵻� 0 */
int ListEmpty(SqList L);

//(4)�����Ա�ĳ���
/* �����㷵��˳��� L �ĳ��� */ 
int ListLength(SqList L);

//(5)������Ա�
/* �����㵱���Ա� L ��Ϊ��ʱ,˳����� L �и�����Ԫ�ص�ֵ */ 
void DispList(SqList L);

//(6.1)��ĳ������Ԫ��ֵ
/* �����㷵�� L �е� i��Ԫ�ص�ֵ*/ 
int GetElem1(SqList L, int i);
//(6.2)��ĳ������Ԫ��ֵ
void GetElem2(SqList L, int i,ElemType *e);

//(7)��Ԫ��ֵ���� 
/* ������˳����ҵ�һ����e��ȵ�����Ԫ�ص�λ�á���������Ԫ�ز�����,�򷵻�ֵΪ 0 */
int LocateElem(SqList L,ElemType e);

//(8.1)��������Ԫ��
/*��������˳��� L �ĵ� i ��λ��(1��i��ListLength(L)+1)�ϲ����µ�Ԫ�� e */ 
int ListInsert(SqList *L,int i,ElemType e);
//(8.2)��������Ԫ��
/*������������˳���Ĳ��룬���մ�С�����˳��*/
int Insert(SqList *L, ElemType x);

//(9)���������Ĺ鲢
void MergeList(SqList La, SqList Lb, SqList *PLc);
