#include<stdio.h>
#include<string.h>
#define Max 1000
int main()
{
    char a[Max],b[Max];
    int c[Max],d[Max],e[Max];
    int a1,a2;
	int i,j;
	int x=0;
	scanf("%s",a);
	scanf("%s",b);
	

   
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        memset(e,0,sizeof(e));
        a1=strlen(a);
        a2=strlen(b);
 
     
        for(i=a1-1; i>=0; i--)
        {
            c[x]=a[i]-48;
            x++;
        }
 
        x=0;
        for(i=a2-1; i>=0; i--)
        {
            d[x]=b[i]-48;
            x++;
        }
 
 
        for(i=0; i<a1; i++)
        {
            for(j=0; j<a2; j++)
            {
                e[i+j]+=(c[i]*d[j]);
            }
        }
 
 
        for(j=0; j<Max; j++)
        {
 
            if(e[j]>=10)
            {
                e[j+1]+=e[j]/10;
                e[j]%=10;
            }
        }
 
        
        for(i=Max-1; i>=0; i--)
        {
            if(e[i]!=0)
                break;
        }
		if(i==-1) printf("0");
        for(; i>=0; i--)
        {
            printf("%d",e[i]);
        } 
    return 0;
}
