#include "CommonDef.h"
//线性表存储空间的初始分配量
typedef struct{
	ElemType *elem;//存储区域基地址
	int length;//当前有效长度
	int listsize;//当前分配的存储容量
}SqList;

//(1)初始化线性表
/* 该运算的结果是构造一个空的线性表 L，为线性表分配存储空间用于存放数据元素, 成功返回 1 ,否则为 0 */ 
int InitList(SqList *L);

//(2)销毁线性表
/* 该运算的结果是释放线性表 L 占用的内存空间 */
void DestroyList(SqList *L);

//(3)判定是否为空表
/* 该运算返回一个值表示 L 是否为空表。若 L 为空表,则返回 1,否则返回 0 */
int ListEmpty(SqList L);

//(4)求线性表的长度
/* 该运算返回顺序表 L 的长度 */ 
int ListLength(SqList L);

//(5)输出线性表
/* 该运算当线性表 L 不为空时,顺序输出 L 中各数据元素的值 */ 
void DispList(SqList L);

//(6.1)求某个数据元素值
/* 该运算返回 L 中第 i个元素的值*/ 
int GetElem1(SqList L, int i);
//(6.2)求某个数据元素值
void GetElem2(SqList L, int i,ElemType *e);

//(7)按元素值查找 
/* 该运算顺序查找第一个与e相等的数据元素的位置。若这样的元素不存在,则返回值为 0 */
int LocateElem(SqList L,ElemType e);

//(8.1)插入数据元素
/*该运算在顺序表 L 的第 i 个位置(1≤i≤ListLength(L)+1)上插入新的元素 e */ 
int ListInsert(SqList *L,int i,ElemType e);
//(8.2)插入数据元素
/*该运算是有序顺序表的插入，按照从小到大的顺序*/
int Insert(SqList *L, ElemType x);

//(9)两个有序表的归并
void MergeList(SqList La, SqList Lb, SqList *PLc);
