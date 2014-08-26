#include<iostream>
#include<cstring>
using namespace std;
int dp[1001][1001];

int solve(int h1, int a1)
{
	if(h1<=0 || a1<=0)
	return 0;
	if(dp[h1][a1]!=-1)
	return dp[h1][a1];
	int max1=1;
///	ans++;
	h1+=3;
	a1+=2;
	if(h1>5&&a1>10)
	{
		max1=max(max1,2+solve(h1-5,a1-10));
	}
	if(h1>20)
	{
			max1=max(max1,2+solve(h1-20,a1+5));
	}
	
	dp[h1-3][a1-2]=max1;
	return max1;
	
}
int main()
{
	int t,h,a;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		memset(dp,-1,sizeof(dp));
		scanf("%d %d",&h,&a);
		printf("%d\n",solve(h,a));
	}
	return 0;
}
