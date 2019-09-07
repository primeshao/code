#include<stdio.h>
int getDaySum(int a,int b,int c)
{
    int sum=0,i;
    int p[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int r[]={31,29,31,30,31,30,31,31,30,31,30,31};
    if((a%4==0&&a%100!=0)||a%400==0)
    {
        for(i=0;i<b-1;i++)
        {
            sum+=r[i];
        }
    }
    else for(i=0;i<b-1;i++)
         {
            sum+=p[i];
         } 
    sum+=c;
    return sum;
}
int getFirstDay(int year)
{
	int sum=0;
	if(year>2011)
	{
		while(year>2011)
		{
			year--;
			if(year%4==0&&year%100!=0||year%400==0) sum+=2;
			else sum+=1;
		}
		return (sum+6)%7;
	}
	while(year<2011)
	{
		if(year%4==0&&year%100!=0||year%400==0) sum-=2;
		else sum-=1;
		year++;
	}
	return 6+sum%7;
}
int main()
{
	int n;
	int i;
	int fd;
    int a,b,c;
	int sum;
	int d[8];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(i=0;i<8;i++) d[i] = 0;
		sum = getDaySum(a,b,c);
		fd = getFirstDay(a);
		for(i=fd;sum--;i++)
		{
			if(i>7) i=i/7;
			d[i]++;
		}
		printf("%d %d\n",d[i-1],i-1);	
	}
	return 0;
}