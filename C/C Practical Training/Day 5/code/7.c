#include<stdio.h>
int gcd(int m, int n)
{
    return (n == 0) ? m : gcd(n, m % n);
}
int main()
{
	int i,j;
	int c[100001];
	for(i=0;i<=100000;i++) c[i] = 0;
    for(i=2;i<=100000;i++) 
	{
		if(c[i]==0)
		{
			for(j=2*i;j<=100000;j=j+i) c[j]=1;
		}
	}
	for(i=0;i<=100000;i++) printf("%d ",c[i]);
    return 0;
}
