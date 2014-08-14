#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

void toBinary(long long int num, int &digits)
{
	int j=0;
	while(digits>0)
	{
		if(num%2==1)
		{
			digits--;
			toBinary(num/2,digits);
			printf("6");
		}
		else
		{
			digits--;
			toBinary(num/2,digits);
			printf("5");
		}
	}
}

int main()
{
    int t;
    long long int num,temp,n,ans,k,rem;
    int i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&num);
        temp=2;
        i=1;
        while(num-temp>0)
        {
        	num=num-temp;
        	temp*=2;
        	i++;
        }
        
        num--;
        toBinary(num,i);
        printf("\n");
	}
    return 0;
}
