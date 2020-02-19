#include<stdio.h>
int main()
{
	long n,m,p;
	long a;
	long b=1;
	scanf("%ld%ld%ld",&n,&m,&p);
	a=n%p;
	if(a==0) {printf("0");return 0;}
	while(m--)
	{
		b = b*a;
		b = b%p;
	}
	printf("%ld",b);
	return 0;
}