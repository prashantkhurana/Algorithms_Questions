#include<iostream>
#include<stdio.h>
using namespace std;

struct mix
{
	int color;
	int smoke;
};

int getM(struct mix dp[][102], int n)
{
	for(int k=1;k<n;k++)
	{
		for(int i=0;i<n-k;i++)
		{
			dp[i][i+k].color=(dp[i][i].color+dp[i+1][i+k].color)%100;
			dp[i][i+k].smoke=dp[i][i].color* dp[i+1][i+k].color+dp[i][i].smoke+dp[i+1][i+k].smoke;
			//printf("%d\n",dp[i][i+k].smoke);
			for(int j=i+1;j<i+k;j++)
			{
				if(dp[i][j].color*dp[j+1][i+k].color+dp[i][j].smoke+dp[j+1][i+k].smoke<dp[i][i+k].smoke)
				{
					dp[i][i+k].color=(dp[i][j].color+dp[j+1][i+k].color)%100;
					dp[i][i+k].smoke=dp[i][j].color*dp[j+1][i+k].color+dp[i][j].smoke+dp[j+1][i+k].smoke;
				//	printf("%d\n",dp[i][i+k].smoke);
				}
			}
		}
	}
	return dp[0][n-1].smoke;
}

int main()
{
	int n;
	struct mix dp[102][102];
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&dp[i][i].color);
			dp[i][i].smoke=0;
		}
		printf("%d\n",getM(dp,n));
	}
	return 0;

}
