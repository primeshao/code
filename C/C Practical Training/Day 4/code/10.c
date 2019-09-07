#include<stdio.h>
#include<string.h>
void f(int **x)
{;}
int main()
{
	int N;
	int LEN;
	int i,j,k1,k2;
	char a[102][51];
	char str[51];
	for(i=0;i<102;i++) for(j=0;j<51;j++) a[i][j] = ' ';
	scanf("%s",str);
	LEN = strlen(str);
	i = 51;
	if(str[0]=='R') a[i][0] = '/';
	if(str[0]=='C') a[i][0] = '_';
	if(str[0]=='F') a[i][0] = '\\';
	for(j=1;j<LEN;j++)
	{
		if(str[j]=='R')
		{
			for(k1=0,k2=j-1;k1<102;k1++)
			{
				if(a[k1][k2]=='/') {i--;break;}
			}	
			a[i][j] = '/';		
		}
		if(str[j]=='C') 
		{
			for(k1=0,k2=j-1;k1<102;k1++)
			{
				if(a[k1][k2]=='/') {i--;break;}
			}
			a[i][j] = '_';
		}	
		if(str[j]=='F')
		{
			for(k1=0,k2=j-1;k1<102;k1++)
			{
				if(a[k1][k2]=='_') {i++;break;}
				if(a[k1][k2]=='\\') {i++;break;}
			}
			a[i][j] = '\\';		
		}
	}
	for(i=0;i<102;i++)
	{
		for(N=LEN-1;N>=0;N--) 
		{
			if(a[i][N]!=' ') break;
		}
		if(N!=-1)
		{
			for(j=0;j<=N;j++) printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
