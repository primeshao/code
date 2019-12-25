#include "Queue.h"

//╤сап
void InitQueue(CirQueue *Q)
{
	Q->front=Q->rear=0;
	Q->count=0;
}

int QueueEmpty(CirQueue *Q)
{
	return Q->count==0;
}

int QueueFull(CirQueue *Q)
{
	return Q->count==QueueSize;
}

void EnQueue(CirQueue *Q,int x)
{
	if(QueueFull(Q))
		printf("Queue overflow");
	else
	{
		Q->count++;
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%QueueSize;
	}
}

int DeQueue(CirQueue *Q)
{
	int temp;
	if(QueueEmpty(Q))
	{
		printf("Queue underflow");
		return -1;
	}
	else
	{
		temp=Q->data[Q->front];
		Q->count--;
		Q->front=(Q->front+1)%QueueSize;
		return temp;
	}
}