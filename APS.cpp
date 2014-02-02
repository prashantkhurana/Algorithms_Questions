#include<stdio.h>
#include<string.h>

#define max 10000000
//bool prime[max];
long long int list[max];
//long long int res[max];
void markMultiples(int n)
{
	int x=n;
	int i=2;
	while(x<max)
	{
		if(list[x]==0)
		list[x]=n;
		x=n*i;
		i++;
	}
}
void sieve()
{
	memset(list,0,sizeof(list));
	//memset(res,0,sizeof(res);
long long int i,num,j;
for(i=2;i<max;i++)
	{
	if(list[i]==0)
		{
			markMultiples(i);
		}
	}
}

long long int compute(int n)
{
long long int i;
long long int res=0;
for(i=2;i<=n;i++)
	res+=list[i];
return res;
}

int main()
{
long long int t,i,n,j;
//long long int res=0;
sieve();
scanf("%lld",&t);
while(t--)
	{
	scanf("%lld",&n);
	printf("%lld\n\n",compute(n));
	}
return 0;
}
