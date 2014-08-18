#include<stdio.h>

int GCD(long long a, long long b)
{
    if (b==0)
        return a;

    else
            return GCD (b,a%b);
}

long long LCM(long long a, long long b)
{
	return (a*b)/GCD(a,b);
}

int main()
{
	char s[30];
	int j,flag;
	long long product;
	
    while(1)
    {
	scanf("%s",s);
	if(s[0]=='*')
	break;
	//gcd=-1;
	product=1;
	flag=1;
	j=0;
	for(int i=0; s[i]!='\0' ; i++)
	{
		j++;
		if(s[i]=='Y')
		{
			product=LCM(product,j);
		}
		
	}
	for(int i=0; s[i]!='\0' ; i++)
	{

		if(s[i]=='N')
		{
			if(product%(i+1)==0)
			{
				printf("-1\n");
				flag=0;
				break;
			
			}
			
		}
	}
		
	if(flag)
	printf("%lld\n",product);
	
	}
    return 0;
}
