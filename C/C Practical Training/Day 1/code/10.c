#include<stdio.h>
int main()
{
	int a[100];
	int n,i,c,d,b;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<100;i++) a[i] = 0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=n-1;i>=1;i--)
		{
			c=a[i]>a[i-1]?a[i]:a[i-1];
			d=a[i]>a[i-1]?a[i-1]:a[i];
			b=c;
			while(b%d!=0)b=b+c;
			a[i-1]=b;
		}
		printf("%d\n",a[0]);
	}
	return 0;
}
