#include<stdio.h>
#include<string.h>
int main()
{
	int count = 0;
	int n,i,j,k,temp;
	char sum[3][3];
	int a,b,c;
	char str[15],set;
	while(scanf("%s",str)!=EOF)
	//while(gets(str)!=NULL)
	{
		for(i=0;i<3;i++)
		{
			sum[0][i] = '0';
			sum[1][i] = '0';
			sum[2][i] = '0';
		}
		n = strlen(str);
		if(str[n-1]=='?') continue;
		for(i=0;i<n;i++)
		{
			if(str[i]=='+') {set='+';break;}
			if(str[i]=='-') {set='-';break;}
		}
		for(k=i-1,j=0;k>=0;k--,j++) sum[0][j] = str[k];
		a = 100*(sum[0][2]-'0')+10*(sum[0][1]-'0')+(sum[0][0]-'0');
		temp = i+1;
		for(i++;i<n;i++)
		{
			if(str[i]=='=') break;
		}
		for(k=i-1,j=0;k>=temp;k--,j++) sum[1][j] = str[k];
		b = 100*(sum[1][2]-'0')+10*(sum[1][1]-'0')+(sum[1][0]-'0');
		for(k=n-1,j=0;k>=i+1;k--,j++) sum[2][j] = str[k];
		c = 100*(sum[2][2]-'0')+10*(sum[2][1]-'0')+(sum[2][0]-'0');
		//printf("a=%d,b=%d,c=%d\n",a,b,c);
		switch(set)
		{
		case '+': if(a+b==c) count++;
		case '-': if(a-b==c) count++;
		}	
	}
	printf("%d",count);
	return 0;
}