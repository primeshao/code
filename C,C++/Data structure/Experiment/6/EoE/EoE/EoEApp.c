#include "EoEDef.h"

//�����ջ�ĳ�ʼ��
Status OPTR_InitStack(SqStack1 *s)
{
    s->base=(RElemtype*)malloc(STACK_INIT_SIZE* sizeof(RElemtype));
    if(!s->base)
    {
        return 0;
    }
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
	return 1;
}

//������ջ�ĳ�ʼ��
Status OPND_InitStack(SqStack2 *s) 
{
    s->base=(DElemtype*)malloc(STACK_INIT_SIZE* sizeof(DElemtype));
    if(!s->base)
    {
        return 0;
    }
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
	return 1;
}

//ȡ�����ջ��ջ��Ԫ��
RElemtype OPTR_GetTop(SqStack1 *s)    
{
    if(s->top==s->base)
	{
		return -1;
    }
		return  *(s->top-1);
}

//ȡ������ջ��ջ��Ԫ��
DElemtype OPND_GetTop(SqStack2 *s)   
{
    if(s->top==s->base)
	{
		return -1;
    }
		return  *(s->top-1);
}

//ѹջ
Status  OPTR_Push(SqStack1 *s, RElemtype e) 
{
    if(s->top-s->base>=s->stacksize) //ջ��׷�Ӵ���ռ�
    {
		s->base=(RElemtype*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(RElemtype));
		if(!s->base)
		{
        return 0;
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
    return 1;
}

//ѹջ
Status  OPND_Push(SqStack2 *s, DElemtype e)
{
    if(s->top-s->base>=s->stacksize) //ջ��׷�Ӵ���ռ�
    {
		s->base=(DElemtype*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(DElemtype));
		if(!s->base)
		{
        return 0;
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *(s->top)=e;
    s->top++;
    return 1;
}

//��ջ
Status OPTR_Pop(SqStack1 *s, RElemtype *e)
{
    if(s->top==s->base)
		return 0;
    *e=*(--(s->top));//�������ٸ�ֵ
	return 1;
}

//��ջ
Status OPND_Pop(SqStack2 *s, DElemtype *e)
{
    if(s->top==s->base)
		return 0;
    *e=*(--(s->top));//�������ٸ�ֵ
	return 1;
}

//�Ƚ�����������ȼ� 
char Precede(char a,char b)
{
	char f;
	if(a=='+'||a=='-')
	{
		if(b=='+'||b=='-'||b==')'||b=='#')
		    f='>';
		else if(b=='*'||b=='/'||b=='('||b=='^')
		    f='<';
	}
	else if(a=='*'||a=='/'||a=='^')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#'||b=='^')
		   f='>';
		else if(b=='(')
		   f='<';
	}
	else if(a=='(')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='('||b=='^')
		   f='<';
		else if(b==')')
		   f='=';
	}
	else if(a==')')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#'||b=='^')
		   f='>';
	}
	else if(a=='#')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='('||b=='^')
		   f='<';
		else if(b=='#')
		   f='=';
	}
	return f;
}

DElemtype Operate( DElemtype d, char e,DElemtype f)
{
	switch(e)
	{
		case '+' :return d+f;
		case '-' :return d-f;
		case '*' :return d*f;
		case '/' :return d/f;
		case '^' :return pow(d,f);
		default :printf("Error!\n");return 0;
	}
}

//�ж϶����ַ��Ƿ�Ϊ����� 
int In(char e)
{
	if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e==')'||e=='#'||e=='^')
	    return 1;//�� 
	else 
	    return 0; //���� 
}

//������ʽֵ
DElemtype EvaluateExpression()
{
	SqStack1 OPTR;
	SqStack2 OPND;
	RElemtype ch,theta,x;
	DElemtype a,b;
	
	OPND_InitStack(&OPND);//�Ĵ�������������� 
	OPTR_InitStack(&OPTR);//�Ĵ������ 
 
	OPTR_Push(&OPTR,'#');
	
	ch=getchar();
	while(ch!='#'||OPTR_GetTop(&OPTR)!='#')
	{
		if(!In(ch))
		{
			OPND_Push(&OPND,ch-'0');
			ch=getchar();
		}
		else
		{
			switch(Precede(OPTR_GetTop(&OPTR),ch))
			{
				case '<':
					OPTR_Push(&OPTR,ch);
				    ch=getchar();
					break;
				case '>':
					OPTR_Pop(&OPTR,&theta);
					OPND_Pop(&OPND,&b);
					OPND_Pop(&OPND,&a);
					OPND_Push(&OPND,Operate(a,theta,b));
					break;
				case '=':
					OPTR_Pop(&OPTR,&x);
				    ch=getchar();
					break;
			}
		} 
	}
	return OPND_GetTop(&OPND);
}