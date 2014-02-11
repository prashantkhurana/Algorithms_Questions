#include<stdio.h>
#include<iostream>
using namespace std;


int main()
{
long long int i,n,a[1000000],res,mid;

scanf("%lld",&n);

while(n!=0)
	{
	res=0;
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);

	mid = n/2;
	i=mid-1;
	int next=a[mid];
	while(i>=0)
	{
		res+=(next-a[i]-1);
		next--;
		i--;
	}
	i=mid+1;
	next=a[mid];
	while(i<n)
	{
		res+=(a[i]-next-1);
		next++;
		i++;
	}
	printf("%lld\n",res);
	scanf("%lld",&n);	
	}

return 0;
}
