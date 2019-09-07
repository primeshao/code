#include <stdio.h>
#include <string.h>
int main()
{
	char mstr[100],str[100];
    gets(str);
	if(strlen(str)==0) printf("ERROR!\n");
	else
	{
		strcpy(mstr,str);
		while(strlen(str)!=0)
		{
			gets(str);
			if(strlen(mstr)<strlen(str)) strcpy(mstr,str);
		}
		puts(mstr);
		printf("\n");
	}
	return 0;
}

