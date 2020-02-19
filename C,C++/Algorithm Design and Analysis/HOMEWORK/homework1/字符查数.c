#include <stdio.h>
#include <string.h>
int check(char c, char * s)
{
	if((*s) != '\0')
	{
		if((*s) == c)
			return check(c,s+1) + 1;
		else
			return check(c,s+1);	
	}
	return 0;
}
int main()
{
	char str[100];
	char x;
	gets(str);
	scanf("%c",&x);
	printf("%d",check(x,str));
	return 0;
}