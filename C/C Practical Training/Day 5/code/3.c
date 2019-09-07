#include<stdio.h>
struct student
{
	int num;
	char name[20];
	int M;
	int F;
	int S;
	int H;
};
int main()
{
	int t;
	int i,j;
	int a[101];
	struct student stu[101];
	int n,m;
	scanf("%d%d%*c",&n,&m);
	for(i=0;i<n;i++)
	{
		stu[i].num = i;
		scanf("%s",stu[i].name);
		scanf("%d%d%d%d",&stu[i].M,&stu[i].F,&stu[i].S,&stu[i].H);
	}
	for(i=0;i<101;i++) a[i] = i;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[a[i]].H<stu[a[j]].H)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[a[i]].S<stu[a[j]].S)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[a[i]].F<stu[a[j]].F)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[a[i]].M<stu[a[j]].M)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(stu[i].num==a[m-1]) printf("%s\n",stu[i].name);
	}
}