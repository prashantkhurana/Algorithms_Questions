#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;

long long a[1000008];
long long MAX=1000008;

long long read(int index)
{
	long long sum=0;
	while(index>0)
	{
		sum+=a[index];
		index-=(index&-index);
	}
	return sum;
}


void add(long long val, long long index)
{
	while(index<MAX)
	{
		a[index]+=val;
		index+=(index&-index);
	}
}


int main()
{
	int t;
	long long n,x;
	cin>>t;
	while(t--)
	{
		scanf("%lld",&n);
		long long ans=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			if(x!=0){
			add(x,x);
			ans+=read(x-1);
		    }
		}
		printf("%lld\n",ans);
	}
	return 0;
}
