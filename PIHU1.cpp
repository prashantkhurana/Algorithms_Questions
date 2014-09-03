#include<iostream>
#include<algorithm>
using namespace std;

long long n,t,p;
long long  a[1000];
long long j,toget,k;
bool check()
{
	for(int i=0;i<n;i++)
	{
		j=i+1;
		k=n-1;
		while(j<k)
		{
			toget=p-a[i]-a[k];
			while(a[j]<=toget && j<k)
			{
				if(a[j]==toget)
				return true;
				else
				j++;
			}
			k--;
		}
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&p);
		sort(a,a+n);
		if(check())
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	
	return 0;
}
