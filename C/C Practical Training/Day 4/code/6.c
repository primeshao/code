#include<stdio.h>
#include<math.h>
void f(int x[],int y[],int n)
{
	int i,j;
	int AL;
	int count = 1;
	for(i=0;i<n;i++)
	{
		AL =0;
		for(j=0;j<n;j++)
		{
			if(x[i]==y[j]) {AL = 1;break;}
		}
		if(!AL){count = 0;break;}
	}
	if(count) printf("YES");
	else printf("NO");
}
int main()
{
	int n;
	int i;
	int a[1001];
	int b[1001];
	int c[1001];
	scanf("%d",&n);
	for(i=1;i<=n-1;i++) b[i-1] = i;
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n-1;i++) c[i] = abs(a[i]-a[i+1]);
	f(b,c,n-1);
	return 0;
}