#include<stdio.h>
#include <math.h>
int f(int m)
{
	int k,i;
    k=(int)sqrt( (double)m );
    for(i=2;i<=k;i++)
        if(m%i==0)
            break;
    if(i>k)
        return 0;
    else
        return 1;
}
int main()
{
	int x,y;
	int n;
	int count;
	printf("!%d",f(4));
	scanf("%d%d",&x,&y);
	while(!(x==0&&y==0))
	{
		count = 1;
		for(n=x;n<=y;n++)
		{
			if(f(n*n+n+41)) count = 0; 
		}
		if(count) printf("OK\n");
		else printf("Sorry\n");
		scanf("%d%d",&x,&y);	
	}
	return 0;
	
}
