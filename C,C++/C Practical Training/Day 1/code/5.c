#include<stdio.h>
int main()
{
	int k,i,j;
	int x,y;
	scanf("%d",&k);
	for(i=1000;i>=1;i--)
	{
		for(j=i-1;j>=1;j--)
		{
			if(j*(i-j)==i*k)
			{
				x = j;
				y = i-j;
				if(x>=y)
				{
					printf("1/%d=1/%d+1/%d\n",k,x,y);
				}
				
			}
		}
	}

	return 0;
}
