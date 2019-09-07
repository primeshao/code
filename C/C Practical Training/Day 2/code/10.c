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
	int n,i,j,count=0;
	struct Node *head,*p,*s,*temp1,*temp2;
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
	temp1=head;
	scanf("%d",&i);




	if(i>0&&i<=count)
	{
	for(j=0;j<i-1;j++) temp1 = temp1->next;
	temp2 = temp1;
	temp2 = temp2->next;
	temp2 = temp2->next;
	temp1->next = temp2;
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
