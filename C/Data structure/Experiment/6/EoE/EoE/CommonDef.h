#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define  STACKINCREMENT 10

typedef int Status;
typedef char RElemtype;
typedef double DElemtype;

typedef struct{
	RElemtype *base;
	RElemtype *top;
	int stacksize;
}SqStack1;  //运算符栈类型定义

typedef struct{
	DElemtype *base;
	DElemtype *top;
	int stacksize;
}SqStack2;  //操作数栈类型定义