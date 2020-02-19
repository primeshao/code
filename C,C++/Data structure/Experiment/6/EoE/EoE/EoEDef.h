#include "CommonDef.h"

//�����ջ�ĳ�ʼ��
Status OPTR_InitStack(SqStack1 *s);

//������ջ�ĳ�ʼ��
Status OPND_InitStack(SqStack2 *s);

//ȡ�����ջ��ջ��Ԫ��
RElemtype OPTR_GetTop(SqStack1 *s);

//ȡ������ջ��ջ��Ԫ��
DElemtype OPND_GetTop(SqStack2 *s);

//ѹջ
Status  OPTR_Push(SqStack1 *s, RElemtype e);

//ѹջ
Status  OPND_Push(SqStack2 *s, DElemtype e);

//��ջ
Status OPTR_Pop(SqStack1 *s, RElemtype *e);

//��ջ
Status OPND_Pop(SqStack2 *s, DElemtype *e);

//�Ƚ�����������ȼ� 
char Precede(char a,char b);

DElemtype Operate( DElemtype d, char e,DElemtype f);

//�ж϶����ַ��Ƿ�Ϊ����� 
int In(char e);

//������ʽֵ
DElemtype EvaluateExpression();