#include<iostream>

using namespace std;


unsigned long long int choose(int n, int c)
{
	if(n<2*c)
	c=n-c;
	unsigned long long int product=1;
	for(int i=0;i<c;i++)
	{
		product=product*(n-i)/(i+1);
	}
	return product;
}
int main()
{
	int t,m,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&m,&k);
		printf("%llu\n",choose(m-1,k-1));
	}
	return 0;
}
