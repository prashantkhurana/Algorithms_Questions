#include <iostream>
#include<math.h>
using namespace std;


long long till[53];


void init()
{
	till[0]=1;
	for(long long i=1;i<51;i++)
	{
		till[i]=2*till[i-1]-(1<<(i-1))+(1<<i);
	}
}


long long getSum(int a)
{
	long long y=0;
	long long x;
	while(a)
	{
		x=a&-a;
		int count=0;
		while(x!=1)
		{
			count++;
			x=x/2;
		}
		x=a&-a;
		y+=till[count];
		a=a-x;
	}
	return y;
}
int main() {
	long long  a, b;
	cin >> a >> b;
	init();
	long long m=getSum(b);
	long long n=getSum(a-1);
	cout<<m-n<<endl;
	return 0;
}


