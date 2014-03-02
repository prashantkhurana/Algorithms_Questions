#include<iostream>
#include<string.h>

using namespace std;

struct coin
{
	int weight;
	int value;
};


int min(int x, int y)
{
	if(y<0)
	return x;
	else if(y<=x)
	return y;
	else 
	return x;
}


int n;
int dp[10005];
int getMin(int c,struct coin coins[])
{
	for(int i=1;i<=c;i++)
	{
		dp[i]=0x3f3f3f3f;
		for(int j=0;j<n;j++)
		{
			if(i-coins[j].weight>=0)
			dp[i]=min(dp[i],coins[j].value+dp[i-coins[j].weight]);
		}
	}
	return dp[c];
}
int main()
{
	int t,e,f,c,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&e,&f);
		c=f-e;
		scanf("%d",&n);
		struct coin coins[n];
		dp[0]=0;
		for(int i=0;i<n;i++)
		{ 
			scanf("%d %d",&coins[i].value,&coins[i].weight);
		}
		ans=getMin(c,coins);
		if(ans==0x3f3f3f3f)
		printf("This is impossible.\n");
		else
		printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
	}
}

