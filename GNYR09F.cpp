#include <iostream>
#include <vector>
#include<string.h>
using namespace std;


int p,d,n,k;

long long dp[102][100][2];

long long solve(int n , int k, int l)
{
	
	if(n==0&& k==0)
	{
		dp[n][k][l]=1;
		return dp[n][k][l];
	}
	
	if(n==0&& k>0)
	{
		dp[n][k][l]=0;
		return dp[n][k][l];
	}
	if(k<0)
	{
		dp[n][k][l]=0;
		return dp[n][k][l];
	}
	
	if(l!=-1)
	{
		if(dp[n][k][l]!=-1)
		return dp[n][k][l];
	}
	long long ans1,ans2;
	
	if(l==-1)
	{
		ans1=solve(n-1,k,0);
		ans2=solve(n-1,k,1);
		dp[n][k][0]=ans1+ans2;
		return dp[n][k][0];
		
	}
	if(l==0)
	{
		ans1=solve(n-1,k,0);
		ans2=solve(n-1,k,1);
	}
	if(l==1)
	{
		ans1=solve(n-1,k,0);
		ans2=solve(n-1,k-1,1);
	}
	dp[n][k][l]=ans1+ans2;
	return dp[n][k][l];
	
}

int main()
{
	int T;
	cin >> T;
	
	while(T--) {
		memset(dp,-1,sizeof(dp));
		cin >> d >> n >> k;
		cout<<d<<" "<<solve(n,k,-1)<<endl;
	}
	return 0;
}

