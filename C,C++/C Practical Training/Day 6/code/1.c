#include<stdio.h>
#include<string.h>
/*int f(int x)
{
	int sum = 0;
	while(x)
	{
		sum+=(x%10);
		x/=10;
	}
	if(sum<10) return sum;
	else f(sum);
}
*/
int f(int x)
{
	return (x-1)%9+1;
}
int main()
{
	int i;
	char a[10001];
	int x=0;
	int n;
	scanf("%s",a);
	n = strlen(a);
	for(i=0;i<n;i++) x+=(a[i]-'0');
	//scanf("%d",&x);
	printf("%d",f(x));
}
