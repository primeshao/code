#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k;
	char a[81][81];
	char t[81];
	char str[81];
	char b;
	int num[81];
	int len_str,last_num = 0,len_num,len_a;
	gets(str);
	b = getchar();
	len_str = strlen(str);
	for(j=0,i=0;i<len_str;i++)
	{
		if(str[i]==b)
		{
			str[i] = '\0';
			num[j] = i;
			j++;
			last_num = i;
		}
	}
	len_num = j;
	j=0;
	//printf("%d",num[0]);
	for(i=0;i<len_num;i++)
	{
		for(k=0;j<=num[i];j++,k++) a[i][k] = str[j];
		//printf("%d\n",j);
	}
	if(last_num!=len_str-1)
	{
		for(k=0;j<=len_str;j++,k++) a[i][k] = str[j];
		len_a = len_num;
	}
	else len_a = len_num-1;
	//printf("%d\n",len_a);
	for(i=0;i<=len_a-1;i++)
	{
		for(j=i+1;j<=len_a;j++)
		{
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
			}
		}
	}
	if(str[0]=='\0') for(i=1;i<=len_a;i++) printf("%s\n",a[i]);
	else for(i=0;i<=len_a;i++) printf("%s\n",a[i]);
/*
	for(i=0;i<len_num;i++) printf("%d",num[i]);
	printf("%d",last_num);
*/
	return 0;		
}
