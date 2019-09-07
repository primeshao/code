#include<stdio.h>
struct student
{
	int no;
	char name[20];
	char sex;
	int a[3];
	int sum;
};
int main()
{
	double b[100];
	double t;
	int n,i,j;
	struct student stu[100];
	scanf("%d",&n);
	for(i=0;i<n;i++) 
	{
		b[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&stu[i].no);
		scanf("%s",&stu[i].name);
		scanf("%c",&stu[i].sex);
		scanf("%c",&stu[i].sex);
		scanf("%d%d%d",&stu[i].a[0],&stu[i].a[1],&stu[i].a[2]);
		stu[i].sum = stu[i].a[0]+stu[i].a[1]+stu[i].a[2];
		b[i] = stu[i].sum;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(b[i]<b[j])
			{
				t = b[i];
				b[i] = b[j];
				b[j] = t;
			}
		}
	}
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(b[j]==stu[i].sum) 
			{
				printf("%d %s %c %d %d %d %.1f\n",stu[i].no,stu[i].name,stu[i].sex,stu[i].a[0],stu[i].a[1],stu[i].a[2],stu[i].sum/3.0);
				break;
			}
		}
	}




	return 0;
}