#include "polynDef.h"

//多项式创建
LinkList CreatPolyn()
{
	LinkList p,q,r;
	float coef;
	int exp;

	//建立头结点
	p = (LinkList)malloc(sizeof(struct node));
	p->coef = 0;
	p->exp = -1;
	p->next = NULL;
	
	//从键盘获取值
	scanf("%f",&coef);
	scanf("%d",&exp);
	while(coef != 0 || exp !=0 )//结束标志为 0 0
	{
		q = p;
		while(q->next && q->next->exp < exp)
			q = q->next;
		
		if(q->next && q->next->exp == exp)
			q->next->coef += coef;
		else
		{
			r = (LinkList)malloc(sizeof(struct node));
			r->coef = coef;
			r->exp = exp;
			r->next = q->next;
			q->next = r;
		}
		//再次取值
		scanf("%f",&coef);
		scanf("%d",&exp);
	}
	return p;
}

//多项式的打印
void PrintPolyn(LinkList p)
{
	p = p->next;
	if(p)
	{
		while(!p->coef && p)
			p = p->next;
		if(p->exp != 0)
		{
			if(p->coef != 1 && p->coef != -1)
				printf("%.1f",p->coef);
			else if(p->coef == -1)
				printf("-");
			if(p->exp == 1)
				printf("x",p->exp);
			else
				printf("x^%d",p->exp);
		}
		else
			printf("%.1f",p->coef);
		p = p->next;
	}
	while(p)
	{
		if(p->coef > 0)
		{
			if(p->coef == 1 && p->exp != 0)
				printf("+");
			else
				printf("+%.1f",p->coef);
		}	
		if(p->coef < 0)
		{
			if(p->coef == -1 && p->exp != 0)
				printf("-");
			else
				printf("%.1f",p->coef);
		}
		if(p->coef != 0 && p->exp != 0)
		{
			if(p->exp == 1)
				printf("x",p->exp);
			else
				printf("x^%d",p->exp);
		}	
		p = p->next;
	}
	printf("\n");
}

//两个多项式的相加
LinkList AddPolyn(LinkList p1, LinkList p2)
{
	float coef;
	LinkList ps,q,rear;
	//建立头结点
	ps = (LinkList)malloc(sizeof(struct node));
	ps->coef = 0;
	ps->exp = -1;
	ps->next = NULL;
	rear = ps;

	p1 = p1->next;
	p2 = p2->next;

	while(p1 && p2)
	{
		if (p1->exp == p2->exp) 
		{
			if(coef = p1->coef + p2->coef)
			{
				q = (LinkList)malloc(sizeof(struct node));
				q->coef = coef;
				q->exp = p1->exp;
				q->next = NULL;
				rear->next = q;
				rear = q;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp)
		{
			if(p2->coef)
			{
				q = (LinkList)malloc(sizeof(struct node));
				q->coef = p2->coef;
				q->exp = p2->exp;
				q->next = NULL;
				rear->next = q;
				rear = q;
			}
			p2 = p2->next;
		}
		else
		{
			if(p1->coef)
			{
				q = (LinkList)malloc(sizeof(struct node));
				q->coef = p1->coef;
				q->exp = p1->exp;
				q->next = NULL;
				rear->next = q;
				rear = q;
			}
			p1 = p1->next;
		}
	}
	while (p1)
	{
		q = (LinkList)malloc(sizeof(struct node));
		q->coef = p1->coef;
		q->exp = p1->exp;
		q->next = NULL;
		rear->next = q;
		rear = q;
		p1 = p1->next;
	}
	while (p2)
	{
		q = (LinkList)malloc(sizeof(struct node));
		q->coef = p2->coef;
		q->exp = p2->exp;
		q->next = NULL;
		rear->next = q;
		rear = q;
		p2 = p2->next;
	}
	check(ps);
	return ps;
}

//两个多项式的相减
LinkList SubstractPolyn(LinkList p1, LinkList p2)
{
	float coef;
	LinkList ps,q,rear;
	//建立头结点
	ps = (LinkList)malloc(sizeof(struct node));
	ps->coef = 0;
	ps->exp = -1;
	ps->next = NULL;
	rear = ps;

	p1 = p1->next;
	p2 = p2->next;

	while(p1 && p2)
	{
		if (p1->exp == p2->exp) 
		{
			if(coef = p1->coef - p2->coef)
			{
				q = (LinkList)malloc(sizeof(struct node));
				q->coef = coef;
				q->exp = p1->exp;
				q->next = NULL;
				rear->next = q;
				rear = q;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		else if (p1->exp > p2->exp)
		{
			if(p2->coef)
			{
				q = (LinkList)malloc(sizeof(struct node));
				q->coef = p2->coef*-1;
				q->exp = p2->exp;
				q->next = NULL;
				rear->next = q;
				rear = q;
			}
			p2 = p2->next;
		}
		else
		{
			if(p1->coef)
			{
				q = (LinkList)malloc(sizeof(struct node));
				q->coef = p1->coef;
				q->exp = p1->exp;
				q->next = NULL;
				rear->next = q;
				rear = q;
			}
			p1 = p1->next;
		}
	}
	while (p1)
	{
		q = (LinkList)malloc(sizeof(struct node));
		q->coef = p1->coef;
		q->exp = p1->exp;
		q->next = NULL;
		rear->next = q;
		rear = q;
		p1 = p1->next;
	}
	while (p2)
	{
		q = (LinkList)malloc(sizeof(struct node));
		q->coef = p2->coef*-1;
		q->exp = p2->exp;
		q->next = NULL;
		rear->next = q;
		rear = q;
		p2 = p2->next;
	}
	check(ps);
	return ps;
}

//两个多项式的相乘
LinkList MultiplyPolyn(LinkList p1, LinkList p2)
{
	float coef;
    int exp;
	LinkList pp,q1,q2,q,r;
	//建立头结点
	pp = (LinkList)malloc(sizeof(struct node));
	pp->coef = 0;
	pp->exp = -1;
	pp->next = NULL;
	for(q2 = p2->next; q2 ;q2 = q2->next)
	{
		for(q1 = p1->next; q1 ;q1 = q1->next)
		{
			coef = q1->coef * q2->coef;
			exp = q1->exp + q2->exp;

			q = pp;
			while(q->next && q->next->exp < exp)
				q = q->next;
		
			if(q->next && q->next->exp == exp)
				q->next->coef += coef;
			else
			{
				r = (LinkList)malloc(sizeof(struct node));
				r->coef = coef;
				r->exp = exp;
				r->next = q->next;
				q->next = r;
			}
		}
	}
	check(pp);
	return pp;
}

//多项式的销毁
int DestroyPolyn(LinkList * p)
{
	//连同头结点一并销毁
	LinkList pre = (*p);
	LinkList q = (*p)->next;
	for(;q;q = q->next)
	{
		free(pre);
		pre = q;
	}
	free(pre);
	*p = NULL;
	return 1;
}

//检查并销毁系数为0的节点

void check(LinkList p) 
{	
	LinkList q;
	while(p->next!=NULL)
	{
		//当没有到达链表尾部的时候，继续循环 
		if(p->next->coef == 0)
		{
			q=p->next;//保存L->next的指针位置 
			p->next = p->next->next;//改变链表的指针 
			free(q);//释放节点空间q 
		}
		else
			p= p->next;//往下循环
	}
}