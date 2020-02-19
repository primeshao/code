#include <stdio.h>
int main()
{
	int count = 0;
	char a[100];
	char b[20][20];
	int n;
	char m;
	int i,j;
	scanf("%d%c%c",&n,&m,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) b[i][j] = ' ';
	}
	for(i=0;i<(n-1)*4;i++)
	{
		a[i] = m;
		if(m=='Z') m='A';
		else m++;
	}
	for(i=0;i<n;i++,count++) b[0][i] = a[count];
	for(i=1;i<n;i++,count++) b[i][n-1] = a[count];
	for(i=n-2;i>=0;i--,count++) b[n-1][i] = a[count];
	for(i=n-2;i>=1;i--,count++) b[i][0] = a[count];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==n-1) printf("%c\n",b[i][j]);
			else printf("%c ",b[i][j]);
		}
	}




	return 0;
}