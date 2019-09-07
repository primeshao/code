#include<stdio.h>
int f(int i) {return i%1000;}
int g(int i) {return i/1000;}
int main()
{
	int i,j,t;
	int a[10];
	for(i=0;i<10;i++) scanf("%d",&a[i]);
	for(i=0;i<=8;i++)
	{
		for(j=i+1;j<=9;j++)
		{
			if(f(a[i])>f(a[j]))
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i=0;i<=8;i++)
	{
		for(j=i+1;j<=9;j++)
		{
			if(f(a[i])==f(a[j]))
			{
				if(g(a[i])<g(a[j]))
				{
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}	
			}
		}
	}
	printf("%d",a[0]);
	for(i=1;i<5;i++) printf(" %d",a[i]);
	return 0;
}