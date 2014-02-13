#include<iostream>
using namespace std;
int count,j,t,i;
long long int res,n,a1,r,a2,b1,b2,c1,c2,sum,a,b,c,store[10][2];

long long int getC(long long int x, long long int y)
{
	if(x<y)
	return 0;
	return (x*(x-1)/2);
}
int find(long long int a1, long long int a2, long long int b1, long long int b2, long long int c1, long long int c2, long long int sum)
{
	long long int new_sum=sum-a1-b1-c1;
	long long int new_a=a2-a1;
	long long int new_b=b2-b1;
	long long int new_c=c2-c1;
	//long long int new_sum=sum-a1-b1-c1;
	long long int res=getC(new_sum+2,2);
	res=res-getC(new_sum-new_a-1+2,2);
	res=res-getC(new_sum-new_b-1+2,2);
	res=res-getC(new_sum-new_c-1+2,2);
	res=res+getC(new_sum-new_a-new_b-2+2,2);
	res=res+getC(new_sum-new_b-new_c-2+2,2);
	res=res+getC(new_sum-new_a-new_c-2+2,2);
	res=res-getC(new_sum-new_a-new_b-new_c-3+2,2);
	return res%1000000007;
}	

int main()
{


scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res=0;
	count=0;
	scanf("%lld",&sum);

	scanf("%lld %lld",&a1,&a2);
	scanf("%lld %lld",&b1,&b2);
	scanf("%lld %lld",&c1,&c2);
	printf("%d\n",find(a1,a2,b1,b2,c1,c2,sum));
}

return 0;

}
