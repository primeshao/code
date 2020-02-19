#include<stdio.h>
#include<string.h>
int main()
{
	int count;
	char a[1001];
	int b[1001];
	int n,i;
	int c,d;
	int temp;
	count = 0;
	for(i=0;i<=1000;i++)
	{
		b[i] = 0;
	}
	scanf("%s",a);
	while(a[0]!='0')
	{
	n = strlen(a)-1;
	for(i=0;i<=n;i++)
		{
			b[i] = (a[i]-'0');
		}
	for(;n>=3;n--)
	{
		temp = 5*b[n];
		c = temp/10;
		d = temp%10;
		b[n-2] = b[n-2]-c;
		b[n-1] = b[n-1]-d;
		for(i=n;i>=1;i--)
		{
			if(b[i]<0)
			{
				b[i] = b[i]+10;
				b[i-1] = b[i-1]-1;
			}
		}
	}
	count = (100*b[0]+10*b[1]+b[2])%17;
	if(count==0) printf("1\n");
	else printf("0\n");
	for(i=0;i<=1000;i++)
	{
		b[i] = 0;
	}
	scanf("%s",a);
	}
	return 0;
}
	
























