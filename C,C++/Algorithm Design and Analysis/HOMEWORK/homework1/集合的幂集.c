#include <stdio.h>
void P(char *str, int n, int index)
{
	static char t[100];
	if(n==-1) { 
		t[index] = '\0';
		printf("(%s)", t);
		return;
	}
	if(n>=0)
	{
		P(str, n-1, index);
		t[index] = str[n];
		P(str, n-1, index+1);		
	}
}

int main()
{
	int i;
	char s[50];
	int n;
	scanf("%d",&n);
	getchar();
	for(i = n-1;i >= 0;i--)
		scanf("%c", &s[i]);
	s[i] = '\0';
	P(s,n-1,0);
	return 0;
}