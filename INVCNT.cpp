#include<iostream>
#include<string.h>
using namespace std;
#define max 10000005
int f[max],t[max];

int read(int index)
{
	int sum=0;
	while(index>0)
	{
		sum+=t[index];
		index-=(index&(-index));
	}
	return sum;
}


void update(int index, int val)
{
	while(index<=max)
	{
		t[index]+=val;
		index+=(index&-index);
	}
}

int main()
{
	int test,n,v;
	long long inversions;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		inversions=0;
		memset(t,0,sizeof(t));
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v);
			update(v,1);
			inversions+=(read(max)-read(v));
		}
		printf("%lld\n",inversions);
	}
}
