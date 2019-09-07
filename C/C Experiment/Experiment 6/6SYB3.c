#include <stdio.h>
int main()
{
	int strlength(char *s);
	char a[100];
	printf("Please input string:");
	gets(a);
	printf("The length of this string is %d.\n",strlength(a));
	return 0;
}
int strlength(char *s)
{
	int i;
	for(i=0;1;i++)
		if(s[i]=='\0')
			return i;
}
