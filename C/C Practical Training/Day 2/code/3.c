#include<stdio.h>
int f(int n,int x,int y)
{
	if(x!=1&&y!=1&&x!=n&&y!=n)
	{
        return f(n-2,x-1,y-1)+(n-1)*4;
    }
    else
	{
        if(x==1)return y;
        if(y==n)return (n-1)+x;
        if(x==n)return 3*n-y-1;
        if(y==1)return 3*(n-1)+(n-x+1);
    }
 
}
int main()
{
    int n;
	int i,j;
	int a[20][20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			a[i][j] = f(n,i+1,j+1);
			if(j==(n-1)) printf("%d\n",a[i][j]);
			else printf("%d ",a[i][j]);
		}
	}
	return 0;
}