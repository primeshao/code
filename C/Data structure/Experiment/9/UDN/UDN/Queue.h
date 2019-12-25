#include <stdio.h>
#define QueueSize 20
//╤сап
typedef struct
{
	int front,rear,count;
	int data[QueueSize]; 
}CirQueue;

void InitQueue(CirQueue *Q);
int QueueEmpty(CirQueue *Q);
int QueueFull(CirQueue *Q);
void EnQueue(CirQueue *Q,int x);
int DeQueue(CirQueue *Q);