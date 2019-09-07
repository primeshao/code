#include <string.h>
#include <stdio.h>
int isAlp(char a)
{
	if(a>='A'&&a<='Z') return 1;
	if(a>='a'&&a<='z') return 1;
	return 0;
}
int isNum(char a)
{
	if(a>='0'&&a<='9') return 1;
	else return 0;
}
int main()
{
	int N;
	int i;
	int count;
	char a[50];
	int n;
	scanf("%d%*c",&n);
	while(n--)
	{
		scanf("%s",&a);
		count = 1;
		N = strlen(a);
		if(!(isAlp(a[0])||a[0]=='_')) count = 0;
		for(i=1;i<N;i++)
		{
			if(!(isNum(a[i])||isAlp(a[i])||a[i]=='_')) count = 0;
		}
		if(count) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}