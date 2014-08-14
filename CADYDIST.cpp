#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	long long n;
	long long sum;
    long long x;
	std::vector<long long> c,p;
	while(scanf("%lld",&n) && n!=0)
	{
		c.clear();
		p.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			c.push_back(x);
		}
		
		
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			p.push_back(x);
		}
		
		sort(c.begin(),c.end());
		sort(p.begin(),p.end());
		sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=c[n-i-1]*p[i];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
