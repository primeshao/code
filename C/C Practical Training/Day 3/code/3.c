#include<stdio.h>
#include<string.h>
void f1(char str[100],int N)
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		if(str[i]=='@')
		{
			for(k=0,j=i;j<N-1;j++,k++) str[k] = str[j+1];
			str[k] = '\0';
			N = strlen(str);
			f1(str,N);
		}
	}
}
void f2(char str[100],int N)
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		if(str[i]=='#')
		{
			for(k=i-1,j=i;j<N-1;j++,k++) str[k] = str[j+1];
			str[k] = '\0';
			N = strlen(str);
			f2(str,N);
		}
	}
}
int main()
{	
	int count = 0;
	int N;
	char str[100];
	gets(str);
	N = strlen(str);
	f1(str,N);
	N = strlen(str);
	f2(str,N);
	puts(str);
	return 0;
}