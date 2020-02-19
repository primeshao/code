#include<stdio.h>
#include<string.h>
int f(char a)
{
	if(a>='a'&&a<='z') return 1;
	else return 0;
}
int main()
{
	int i,LEN;
	char str[100];
	while(gets(str)!=NULL)
	{
		LEN=strlen(str);
		if(f(str[0]))
			str[0]=str[0]-32;
		for(i=0;i<LEN;i++)
		{
			if(f(str[i])&&str[i-1]==' ')
				str[i]=str[i]-32;
			printf("%c",str[i]);
		}
		printf("\n");
	
	}
	return 0;
}