#include<stdio.h>
int main()
{
	int time =0;
	int temp1,temp2;
	int i,j;
	int T;
	int N;
	int a[1001];
	scanf("%d",&T);
	for(;T;T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++) scanf("%d",&a[i]);
		for(i=0;i<N-1;i++)
		{
			for(j=0;j<N-1-i;j++)
			{
				if(a[j]>a[j+1])
				{ 
					int temp =a[j+1];
					a[j+1] = a[j];
					a[j] = temp;
				}
			}
		}
		while(N>3)
        {
			temp1 = 2*a[1]+a[0]+a[N-1];
			temp2 = a[N-2]+a[0]*2+a[N-1];
            time+= temp1<temp2?temp1:temp2;
			N = N-2;
		}
		if(N==3)
            time+=a[0]+a[1]+a[2];
		if(N==2)
            time+=a[1];
		if(N==1)
            time+=a[0];
		printf("%d\n",time);
		time = 0;
	}
	return 0;
}
