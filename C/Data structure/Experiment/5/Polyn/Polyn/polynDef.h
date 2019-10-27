#include "CommonDef.h"

//多项式创建
LinkList CreatPolyn();

//多项式的打印
void PrintPolyn(LinkList p);

//两个多项式的相加
LinkList AddPolyn(LinkList p1, LinkList p2);

//两个多项式的相减
LinkList SubstractPolyn(LinkList p1, LinkList p2);

//两个多项式的相乘
LinkList MultiplyPolyn(LinkList p1, LinkList p2);

//多项式的销毁
int DestroyPolyn(LinkList * p);

//检查并销毁系数为0的节点
void check(LinkList p);
