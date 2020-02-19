#include<stdio.h>
int main()
{
	int i,j;
	char a[103][103];
	int b[103][103];
	int n,m;
	scanf("%d%d%*c",&n,&m);
	for(i=0;i<103;i++)
	{
		for(j=0;j<103;j++)
		{
			a[i][j] = '#';
			b[i][j] = 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%c",&a[i][j]);
		}
		scanf("%*c");
	}
	for(i=0;i<103;i++)
	{
		for(j=0;j<103;j++)
		{
			if(a[i][j]=='#') b[i][j] = 0;
			if(a[i][j]=='*') b[i][j] = -1;	
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(b[i][j]==0)
			{
				if(a[i-1][j]=='*') b[i][j]++;
				if(a[i+1][j]=='*') b[i][j]++;
				if(a[i][j-1]=='*') b[i][j]++;
				if(a[i][j+1]=='*') b[i][j]++;
				if(a[i-1][j+1]=='*') b[i][j]++;
				if(a[i-1][j-1]=='*') b[i][j]++;
				if(a[i+1][j+1]=='*') b[i][j]++;
				if(a[i+1][j-1]=='*') b[i][j]++;
			}
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			switch(b[i][j])
			{
			case -1 : printf("*");break;
			default : printf("%d",b[i][j]);
			}	
		}
		printf("\n");
	}

/*
	for(i=0;i<103;i++)
	{
		for(j=0;j<103;j++)
		{
			printf("%d",b[i][j]);
		}
		printf("\n");
	}

*/


	return 0;
}