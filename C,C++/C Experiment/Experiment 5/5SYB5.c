#include <stdio.h>
#include <math.h>
int main()
{
	int n,a=1,prime(int);
	for(n=0;prime(a);n++) a=n*n+n+41;
	printf("%d\n",n-1);
	return 0;
}
int prime(int m)
{
	int z,i;
	z=(int)sqrt(m);
	for(i=2;i<=z;i++)
	if(m%i==0) break;
	if(i>z) return 1;
	else return 0;
}
