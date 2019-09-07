#include<stdio.h>
void out(int x[201][201],int n,int m)
{
	int i=0,j=0,r=0;
	int count = n*m;
	while(count) 
	{
        while(i<n-r&&count) 
		{
            if(i==0&&j==0) 
			{
                printf("%d",x[0][0]);
                i++;
            } 
			else printf(" %d",x[i++][j]);
            count--;
        }
        i--;j++;
        while(j<m-r&&count) 
		{
            printf(" %d",x[i][j++]);
            count--;
        }
        j--;i--;
        while(i>=r&&count) 
		{
            printf(" %d",x[i--][j]);
            count--;
        }
        i++;j--;
        while(j>r&&count) 
		{
            printf(" %d",x[i][j--]);
            count--;
        }
        j++;i++;r++;
    }
}
int main() 
{
    int i,j;
    int n,m,count;
	int a[201][201];
    scanf("%d%d",&n,&m);
    count=n*m;
    for(i=0; i<n; i++) for(j=0; j<m; j++) scanf("%d",&a[i][j]);
	out(a,n,m);
    return 0;
}
