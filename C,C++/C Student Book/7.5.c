#include <stdio.h>
int main()
{
	void link(char a[],char b[]);
	char string1[100],string2[100];
	printf("Please input string1:");
	gets(string1);
	printf("Please input string2:");
	gets(string2);
	link(string1,string2);
	puts(string1);
	return 0;
}
void link(char *a,char *b)
{
	int i,j;
	for(i=0;1;i++)
		if(a[i]=='\0') break;
	for(j=0;1;j++)
	{
		if(b[j-1]=='\0') break;/*�ð������е����⣬û���ǵ�b[-1]����������ø���*/
		*(a+i+j)=b[j];
	}
}