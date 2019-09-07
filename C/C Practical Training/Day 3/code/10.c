#include<stdio.h>
#include<string.h>
void add(char a[],char b[])
{
	int s[501];
	int len1=strlen(a)-1;
	int len2=strlen(b)-1;
	int d=0;
	int c=0;
	int i;
	int w;
	while(len1>=0 || len2>=0)
	{
		w=0;
		if(len1>=0) w+=a[len1]-'0';
		if(len2>=0) w+=b[len2]-'0';
		w+=c;
		s[d]=w%10;
		c=w/10;
		d++;
		len1--;
		len2--;
	}
	while(c)
	{
		s[d++]=c%10;
		c/=10;
	}
	for(i=d-1;i>=0;i--)
	printf("%d",s[i]);
	printf("\n");
}
void sub1(char a[],char b[])
{
	int z[501]={0};
	int len1,len2; 
	int x[501]={0},y[501]={0};
	int i,j=0,k=0;  
    len1=strlen(a);  
	len2=strlen(b);  
	for(i=len1-1,j=0;i>=0;i--) x[j++]=a[i]-'0';  
    for(i=len2-1,k=0;i>=0;i--) y[k++]=b[i]-'0';  
    if(len1>len2) {for(i=0;i<len1;i++)  
    {  
        if(x[i]>=y[i]) z[i]=x[i]-y[i];  
        else    
        {  
            z[i]=x[i]+10-y[i];  
            x[i+1]=x[i+1]-1;  
        }      
    }  
    for(i=len1-1;i>0;i--) 
    {  
        if(z[i]==0) len1--;  
        else break;   
    }  
    for(i=len1-1;i>=0;i--) printf("%d",z[i]);  
    printf("\n"); }
    else if(len1<len2)  
	{  
		printf("-");  
        
for(i=0;i<len2;i++)  
    {  
        if(y[i]>=x[i]) z[i]=y[i]-x[i];  
        else    
        {  
            z[i]=y[i]+10-x[i];  
            y[i+1]=y[i+1]-1;  
        }      
    }  
    for(i=len2-1;i>0;i--) 
    {  
        if(z[i]==0) len2--;  
        else break;   
    }  
    for(i=len2-1;i>=0;i--) printf("%d",z[i]);  
    printf("\n");   
    }   
	else 
	{  
		for(i=len1-1;i>=0;i--)
		{  
			if(x[i]==y[i]) continue;  
			if(x[i]>y[i])   
			{  
				
				for(i=0;i<len1;i++)  
    {  
        if(x[i]>=y[i]) z[i]=x[i]-y[i];  
        else    
        {  
            z[i]=x[i]+10-y[i];  
            x[i+1]=x[i+1]-1;  
        }      
    }  
    for(i=len1-1;i>0;i--) 
    {  
        if(z[i]==0) len1--;  
        else break;   
    }  
    for(i=len1-1;i>=0;i--) printf("%d",z[i]);  
    printf("\n");  
				break;  
			}      
			if(x[i]<y[i])
			{  
				printf("-");  
                for(i=0;i<len1;i++)  
    {  
        if(y[i]>=x[i]) z[i]=y[i]-x[i];  
        else    
        {  
            z[i]=y[i]+10-x[i];  
            y[i+1]=y[i+1]-1;  
        }      
    }  
    for(i=len1-1;i>0;i--) 
    {  
        if(z[i]==0) len1--;  
        else break;   
    }  
    for(i=len1-1;i>=0;i--) printf("%d",z[i]);  
    printf("\n");  
                break;   
            }      
        }  
	} 
}

int main()
{
	int n;
	int count;
	int i,j;
	int LEN;
	char a[501];
	char num1[501];
	char num2[501];
	scanf("%d%*c",&n);
	while(n--)
	{
		count = 1;
		scanf("%s",a);
		LEN = strlen(a);
		for(i=0;i<LEN;i++)
		{
			if(a[i]=='+') 
			{
				num1[i] = '\0';
				break;
			}
			if(a[i]=='-')
			{
				num1[i] = '\0';
				count = 0;
				break;
			}
			num1[i] = a[i];
		}
		for(i=strlen(num1)+1,j=0;i<LEN;i++,j++) num2[j] = a[i];
		num2[j] = '\0';
		if(count) add(num1,num2);
		else sub1(num1,num2);
	}
	return 0;
}
