#include<iostream>
#include<math.h>

using namespace std;


int getdigits(int num)
{
	int k=0;
	while(num>0)
	{
		int digit=num%2;
		k=k*2+digit;
		num/=2;
	}
	return k;
}
int main()
{
	int n,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		if(x%2==0)
		{
			int numdigits=getdigits(x);
			x=numdigits;
		}
		printf("%d\n",x);
	}
	return 0;
}
