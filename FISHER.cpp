#include <cstdio>
#include <iostream> 
#include<climits>
using namespace std;

int main() {
	int dp[52][1002];
	int tolls[52][52];
	int time[52][52];
	int i,j,t;
	int n, T;
	
	
while(true) {
	scanf("%d%d",&n,&T);
	if(n==0 && T==0) break;
	
	for(i=1;i<=n;i++)
	{
		for(int j=0;j<=T;j++)
		dp[i][j]=INT_MAX;
	}
 	
 	for(i=0;i<=1000;i++) dp[n][0]=0;
 	
 	
	for(i=1;i<=n;i++) 
		for(j=1;j<=n;j++)
			scanf("%d",&time[i][j]);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) 
			scanf("%d",&tolls[i][j]);
	
	
	for(t=0;t<=T;t++)
	{
		for(i=1;i<n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(j!=i)
				{
					if(t-time[i][j]>=0)
					{
						if(dp[j][t-time[i][j]]!=INT_MAX && dp[j][t-time[i][j]]+tolls[i][j]<dp[i][t] )
						{
							dp[i][t]=dp[j][t-time[i][j]]+tolls[i][j];
						}
					}
				}
			}
		}
	}
	int res_cost=INT_MAX;
	int res_time=INT_MAX;
	for(i=0;i<=T;i++)
	{
		if(dp[1][i]<res_cost)
		{
			res_cost=dp[1][i];
			res_time=i;
		}
		
	}
	
		
	printf("%d %d\n",res_cost,res_time);
}

	return 0;
	
}

