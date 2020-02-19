#include<stdio.h>
#include<string.h>
int main()
{
	char a1[1001],a2[1001];
	int b1[1001],b2[1001];
	int sum[1001];
	int m,n,i,j,k,p,q;
	int count = 0;
	for(i=0;i<=1000;i++)
	{
		b1[i] = 0;
		b2[i] = 0;
	}
	scanf("%s",a1);
	n = strlen(a1);
	for(i=0;i<n;i++)
	{
		b1[i] = (a1[n-i-1]-'0');
	}
	scanf("%s",a2);
	m = strlen(a2);
	for(j=0;j<m;j++)
	{
		b2[j] = (a2[m-j-1]-'0');
	}
	for(k=0;k<1001;k++)
	{
		sum[k] = b1[k] + b2[k];
	}
	for(p=0;p<1001;p++)
	{
		sum[p+1] = sum[p+1]+sum[p]/10;
		sum[p] = sum[p]%10;
	}
	for(q=1000;q>=0;q--)
	{
		if(sum[q]!=0)
		{
			count = 1;
			break;
		}
	}
	if(count)
	{
		for(;q>=0;q--)
		{
			printf("%d",sum[q]);
		}
	}
	else printf("0");	
	return 0;
}
