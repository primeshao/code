#include "polynDef.h"

//����ʽ����
LinkList CreatPolyn()
{
	LinkList p,q,r;
	float coef;
	int exp;

	//����ͷ���
	p = (LinkList)malloc(sizeof(struct node));
	p->coef = 0;
	p->exp = -1;
	p->next = NULL;
	
	//�Ӽ��̻�ȡֵ
	scanf("%f",&coef);
	scanf("%d",&exp);
	while(coef != 0 || exp !=0 )//������־Ϊ 0 0
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
		//�ٴ�ȡֵ
		scanf("%f",&coef);
		scanf("%d",&exp);
	}
	return p;
}

//����ʽ�Ĵ�ӡ
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

//��������ʽ�����
LinkList AddPolyn(LinkList p1, LinkList p2)
{
	float coef;
	LinkList ps,q,rear;
	//����ͷ���
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

//��������ʽ�����
LinkList SubstractPolyn(LinkList p1, LinkList p2)
{
	float coef;
	LinkList ps,q,rear;
	//����ͷ���
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

//��������ʽ�����
LinkList MultiplyPolyn(LinkList p1, LinkList p2)
{
	float coef;
    int exp;
	LinkList pp,q1,q2,q,r;
	//����ͷ���
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

//����ʽ������
int DestroyPolyn(LinkList * p)
{
	//��ͬͷ���һ������
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

//��鲢����ϵ��Ϊ0�Ľڵ�

void check(LinkList p) 
{	
	LinkList q;
	while(p->next!=NULL)
	{
		//��û�е�������β����ʱ�򣬼���ѭ�� 
		if(p->next->coef == 0)
		{
			q=p->next;//����L->next��ָ��λ�� 
			p->next = p->next->next;//�ı������ָ�� 
			free(q);//�ͷŽڵ�ռ�q 
		}
		else
			p= p->next;//����ѭ��
	}
}