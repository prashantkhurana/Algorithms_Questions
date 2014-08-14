#include<iostream>
using namespace std;
#define MAXDIGITS 65
long long a[MAXDIGITS][10];


long long solve_p(int n, int i)
{
	if(a[n][i]!=-1)
	return a[n][i];
	else
	{
		a[n][i]=0;
		for(int j=i;j<10;j++)
		{
			
			a[n][i]+=solve_p(n-1,j);
		}
		return a[n][i];
	}
}

long long solve(int n)
{
	long long ans=0;
	for(int i=0;i<10;i++)
	{
		ans+=solve_p(n,i);
	}
	return ans;
	
	
}
int main()
{
	int p,t,n;
	scanf("%d",&p);
	for(int i=0;i<10;i++)
	{
		a[1][i]=1;
	}
	for(int i=MAXDIGITS;i>1;i--)
	{
		for(int j=0;j<10;j++)
		{
			a[i][j]=-1;
		}
	}
	for(int i=0;i<p;i++)
	{
		scanf("%d %d",&t,&n);
		printf("%d %lld\n",t,solve(n));
	}
}
