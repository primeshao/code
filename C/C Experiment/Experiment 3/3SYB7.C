#include <stdio.h>
#include <math.h>
int main()
{
	int n,m,i;
	printf("Please input num n:");
	scanf("%d",&n);
	if(n<=0) printf("ERROR!!!\n");
	else
	{if(n==1) printf("%d is neither a prime number nor composite number!\n",n);
	 else
	 {
	  m=(int)sqrt(n);
	  for(i=2;i<=m;i++)
	   if(n%i==0) break;
	  if(i>m) printf("%d is a prime number.\n",n);
	  else printf("%d is not a prime number.\n",n);
	 }
	}
	return 0;
}