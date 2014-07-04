#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	long long int t,p,n,e_need,e_have,x;
	scanf("%lld",&t);
	p=1;
	while(t--)
	{
		scanf("%lld",&n);
		e_need=1;
		e_have=1;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&x);
			e_have+=x;
			if(e_have<=0)
			{
				e_need+=(e_have*-1)+1;
				e_have=1;
			}
		}
		printf("Scenario #%lld: %lld\n",p,e_need);
		p++;
	}
	return 0;
}
