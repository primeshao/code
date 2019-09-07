#include<stdio.h>
int main()
{
	int i,j,k;
	int a[41][146];
	int n;
	int h,w;
	scanf("%d",&n);
	w=7*n-1;
	h=2*n-1;
	for(i=0;i<41;i++)
	{
		for(j=0;j<146;j++) a[i][j] = 0;
	}
	for(i=0;i<n;i++) a[i][0] = 1;
	for(i=1;i<(4*n+1);i++) a[n-1][i] = 1;
	for(i=4*n+1,j=n-1,k=w-1;j!=(-1);i++,j--,k--)
	{
			a[j][i] = 1;
			a[h-j-1][i] = 1;
			a[j][k] = 1;
			a[h-j-1][k] = 1;
	}
	for(k=n-2;k!=0;i++,k--)
	{
		a[0][i] = 1;
		a[h-1][i] = 1;
	}
	for(i=0;i<h;i++) 
	{
		for(k=w-1;a[i][k]!=1;k--);
		for(j=0;j<=k;j++)
		{
			switch(a[i][j])
			{
			case 0 : printf(" ");break;
			case 1 : printf("*");break;
			default :;
			}
		}
		printf("\n");
	}

	
	return 0;
}