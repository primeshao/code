#include "LlistDef.h"

void f(List L)
{
	L = NULL;
}

int main()
{
	List La,Lb;
	La = makeEmpty();
	Lb = makeEmpty();
	ListInsert_L(La,1,5);
	ListInsert_L(La,2,10);
	ListInsert_L(La,3,15);
	ListInsert_L(La,4,20);
	ListInsert_L(Lb,1,30);
	ListInsert_L(Lb,2,10);
	ListInsert_L(Lb,3,11);
	Print_L(La);
	Print_L(Lb);
	UnionList_L(La,Lb);
	f(La);
	Print_L(La);
	//Print_L(Lb);
	return 0;
}