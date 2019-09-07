#include <stdio.h>
#include <math.h>
int main()
{
	int a,prime(int);
	printf("Please input num:");
	scanf("%d",&a);
	if(prime(a)==1) printf("%d is a prime number.\n",a);
	if(prime(a)==0) printf("%d is not a prime number.\n",a);
	if(prime(a)==-1) printf("%d is neither a composite number nor a prime number.\n",a);
    return 0;
}
int prime(int m)
{
	if(m==1) return -1;
	else
	{
	int z,i;
	z=(int)sqrt(m);
	for(i=2;i<=z;i++)
	if(m%i==0) break;
	if(i>z) return 1;
	else return 0;
	}
}
