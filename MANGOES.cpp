#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
	unsigned long long  t,n;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&n);
		unsigned long long  p=ceil(n/2.0)-1;
		unsigned long long z=(p*p)%n;
		cout<<z<<endl;
	}
	return 0;
}
