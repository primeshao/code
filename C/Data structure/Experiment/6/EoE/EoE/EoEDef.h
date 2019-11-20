#include "CommonDef.h"

//运算符栈的初始化
Status OPTR_InitStack(SqStack1 *s);

//操作数栈的初始化
Status OPND_InitStack(SqStack2 *s);

//取运算符栈的栈顶元素
RElemtype OPTR_GetTop(SqStack1 *s);

//取操作数栈的栈顶元素
DElemtype OPND_GetTop(SqStack2 *s);

//压栈
Status  OPTR_Push(SqStack1 *s, RElemtype e);

//压栈
Status  OPND_Push(SqStack2 *s, DElemtype e);

//出栈
Status OPTR_Pop(SqStack1 *s, RElemtype *e);

//出栈
Status OPND_Pop(SqStack2 *s, DElemtype *e);

//比较运算符的优先级 
char Precede(char a,char b);

DElemtype Operate( DElemtype d, char e,DElemtype f);

//判断读入字符是否为运算符 
int In(char e);

//计算表达式值
DElemtype EvaluateExpression();