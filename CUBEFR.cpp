#include<iostream>
using namespace std;

#define N 1000000
#define sqrt(N) 1000

int primes[N];


void uncheck(long long p)
{
	long long y=p*p*p;
	long long x=y;
	while(x<=N)
	{
		primes[x]=0;
		x=x+y;
	}
}


void generatePrimes()
{
	for(int i=1;i<=N;i++)
	primes[i]=1;
	int j=2;
	for(long long i=2;i<=N;i++)
	{
		if(primes[i])
		{
			primes[i]=j++;
			uncheck(i);
		}
	}
}

int main()
{
	generatePrimes();
	
	int t,n;
 	scanf("%d",&t);
 	for(int i=1;i<=t;i++)
 	{
  	scanf("%d",&n);
  	if(primes[n]!=0)
   printf("Case %d: %d\n",i,primes[n] );
  else
   printf("Case %d: Not Cube Free\n",i);
 	}
//	for(int i=1;i<=N;i++)
//	if(!primes[i])cout<<i<<" ";
	return 0;
}
