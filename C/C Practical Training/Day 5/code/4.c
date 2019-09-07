#include<math.h>
#include<stdio.h>
int isPrime(int x)
{
	int k,i;
    k=(int)sqrt((double)x);
    for(i=2;i<=k;i++)
        if(x%i==0)
            break;
    if(i>k)
        return 1;
    else
        return 0;
}
int isTwo(int x)
{
	while(x!=1)
	{
		if(x%2!=0) return 0;
		x/=2;
	}
	return 1;
}
int isThree(int x)
{
	while(x!=1)
	{
		if(x%3!=0) return 0;
		x/=3;
	}
	return 1;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(isPrime(n)) printf("H\n");
		else if(isTwo(n)) printf("D\n");
		else if(isThree(n)) printf("W\n");
		else printf("O\n");
	}
	return 0;
}