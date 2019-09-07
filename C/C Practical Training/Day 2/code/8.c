#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct student)
struct student
{
	int num;
	struct student *next;
};
int main()
{
	int n;
	struct student *head,*p;
	head=p=(struct student *)malloc(LEN);
	p->next = NULL;
	scanf("%d",&n);
	while(n!=0)
	{
		p=(struct student *)malloc(LEN);
		p->num = n;
		p->next = head->next;
		head->next = p;
		scanf("%d",&n);
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
	printf("\n");
	return 0;
}
