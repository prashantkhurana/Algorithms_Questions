#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


#define max 1000005
//bool prime[max];
long long int list[max];
long long int primes[max];
//long long int res[max];
void markMultiples(int n)
{
	int x=n*2;
	int i=3;
	while(x<max)
	{
		list[x]=1;
		x=n*i;
		i++;
	}
}
void sieve()
{
	memset(list,0,sizeof(list));
	list[1]=1;
	//memset(res,0,sizeof(res);
long long int i,num,j=0;;
for(i=2;i<max;i++)
	{
	if(list[i]==0)
		{
			primes[j++]=i;
			markMultiples(i);
		}
	}
}

int checkPrime(long long int x)
{
	for(int i=0;primes[i]*primes[i]<=x;i++)
	{
		if(x%primes[i]==0)
		return 0;
	}
	return 1;
}



int main()
{
long long int n,i,t;
//long long int res=0;
sieve();
int count=0;
scanf("%lld",&t);
while(t--)
{
	count=1;
	vector<long long int> t;
	scanf("%lld",&n);
	if(n%2)
	{
		printf("0\n");
		continue;	
	}
	long long int x=n/2;
	int set=0;
	t.push_back(1);
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			set=1;
			if(list[i]==1)
			{
				t.push_back(i);
				count++;				
			}
			if((x/i)<max)
			{
				if(list[x/i]==1&&(x/i)!=i)
				{
					t.push_back(x/i);
					count++;
				}
			}
			else if(!checkPrime(x/i))
			{
					t.push_back(x/i);
					count++;
			}
			
		}
	}
	if(set)
	{
		t.push_back(x);
		count++;
	}
	
	
	sort(t.begin(),t.end());
	printf("%d ",count);
	for(int i=0;i<t.size();i++)
	{
		printf("%lld ",t[i]);
	}
	printf("\n");
}

return 0;
}
