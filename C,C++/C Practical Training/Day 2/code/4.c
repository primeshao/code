#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Student)
struct Student{
	double ave,sum;
	int set;
	int a[5];
    struct Student * next;
};
int main()
{
	int count = 0;
	int i,j;
	struct Student * head;
    struct Student * p;
	struct Student * temp;
	int n,m;
	double b[5];
	for(i=0;i<5;i++) b[i] = 0;
	scanf("%d%d",&n,&m);
	p = (struct Student *)malloc(LEN);
	head = p;
	for(i=1;i<=n;i++)
	{
		temp = (struct Student *)malloc(LEN);
		temp->next = NULL;
		p->next = temp;
		p = temp;
	}
	temp = head;
	for(i=1;i<=n;i++)
	{
		temp = temp->next;
		temp->sum = 0;
		temp->ave = 0;
		for(j=0;j<m;j++) scanf("%d",&(temp->a[j]));
		//printf("%d %d \n",temp->a[0],temp->a[1]);
	}
	temp = head;
	for(i=1;i<=n;i++)
	{
		temp = temp->next;
		for(j=0;j<m;j++)
		{
			temp->sum+=(double)temp->a[j];
			b[j]+=(double)temp->a[j];
		}
		temp->ave = (temp->sum)/m;
	}
	temp = head;
	temp = temp->next;
	printf("%.2f",temp->ave);
	while(temp->next!=NULL)
	{
		temp = temp->next;
		printf(" %.2f",temp->ave);
	}
	printf("\n%.2f",b[0]/n);
	for(i=1;i<m;i++) printf(" %.2f",b[i]/n);
	temp = head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		temp->set = 1;
		for(i=0;i<m;i++)
		{
			if(temp->a[i] < (b[i]/m)) temp->set = 0;
		}
		if(temp->set) count++;
	}
	printf("\n%d\n",count);






}
