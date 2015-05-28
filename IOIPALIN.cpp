#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<stdio.h>
using namespace std;

int dp[2][5001];

char s[5001];
int n;


int miminpalindrome(int start, int end)
{
	for(int l=1;l<n;l++)
	{
		for(int i=0;i<n-l;i++)
		{
			int temp=dp[1][i];
			if(s[i]==s[i+l])
			{
				if(i+1<=i+l-1)
				{
					dp[1][i]=dp[0][i+1];
				}
				else
				dp[1][i]=0;
			}
			else
			{
				if(i+1<=i+l-1)
				{
					dp[1][i]=1+min(dp[1][i+1],dp[1][i]);
				}
				else
				dp[1][i]=1;
			}
			//cout<<i<<" "<<i+l<<" :"<<dp[1][i]<<endl;
			dp[0][i]=temp;
		}
	}
}
int main()
{
//	int n;
	scanf("%d",&n);
	scanf("%s",&s);
//	memset(dp,-1,sizeof(dp));
	miminpalindrome(0,n-1);
	printf("%d\n",dp[1][0]);
	return 0;
}
