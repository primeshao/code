#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct Node)
struct Node
{
	int num;
	struct Node *next;
};

int main()
{
	int n,i,j,x,count=0;
	struct Node *head,*p,*s,*temp;
	head=p=(struct Node *)malloc(LEN);
	p->next = NULL;
	scanf("%d",&n);
	while(n!=0)
	{
		p=(struct Node *)malloc(LEN);
		p->num = n;
		p->next = head->next;
		head->next = p;
		scanf("%d",&n);
	}
	s=head;
	while(s->next!=NULL) {s=s->next;count++;}
	count++;
	temp=head;
	scanf("%d%d",&i,&x);
	if(i>0&&i<=count){





	for(j=0;j<i-1;j++) temp = temp->next;
	s=(struct Node *)malloc(LEN);
	s->num = x;
	s->next = temp->next;
	temp->next = s;


	}



	if(head->next!=NULL)
	{
		head = head->next;
		printf("%d",head->num);
	}
	while(head->next!=NULL)
	{
		head = head->next;
		printf(" %d",head->num);
	}
	return 0;
}
