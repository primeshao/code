#include<stdio.h>
#include<string.h>
int f1(char x[])
{
	int i,n;
	n = strlen(x);
	for(i=0;i<n;i++)
	{
		if(x[i]<='Z'&&x[i]>='A') return 1;
	}
	return 0;
}
int f2(char x[])
{
	int i,n;
	n = strlen(x);
	for(i=0;i<n;i++)
	{
		if(x[i]<='z'&&x[i]>='a') return 1;
	}
	return 0;
}
int f3(char x[])
{
	int i,n;
	n = strlen(x);
	for(i=0;i<n;i++)
	{
		if(x[i]<='9'&&x[i]>='1') return 1;
	}
	return 0;
}
int f4(char x[])
{
	int i,n;
	n = strlen(x);
	for(i=0;i<n;i++)
	{
		switch(x[i])
		{
		case '~':
		case '!':
		case '@':
		case '#':
		case '$':
		case '%':
		case '^': return 1;
		default: ;
		}
	}
	return 0;
}
int main()
{
	int M;
	int n;
	char str[51];
	scanf("%d%*c",&M);
	while(M--)
	{
		scanf("%s",str);
		n = strlen(str);
		if((n>=8&&n<=16)&&(f1(str)+f2(str)+f3(str)+f4(str))>=3) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}