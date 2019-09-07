#include<stdio.h>
int main()
{
	int i;
	int a,b,c;
	int t[10][3];
	scanf("%d",&i);
	while(scanf("%d%d%d%d%d%d",&t[0][0],&t[0][1],&t[0][2],&t[1][0],&t[1][1],&t[1][2])!=EOF)
	{
			c = (t[0][2]+t[1][2])%60;
			b = (t[0][1]+t[1][1]+(t[0][2]+t[1][2])/60)%60;
			a = t[0][0]+t[1][0]+(t[0][1]+t[1][1]+(t[0][2]+t[1][2])/60)/60;
			printf("%d %d %d\n",a,b,c);
	}


	return 0;
}
