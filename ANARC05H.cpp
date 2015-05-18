#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[26][226];

char str[500];
int len;
//int sum;

int numg(int end, int maxsum)
{
		if(end==-1)
	{
		return 1;
	}
	else
	if(dp[end][maxsum]!=-1)
	{
		return dp[end][maxsum];
	}
	else
	{
		//int sum=maxsum;
		int sum2=0;
		dp[end][maxsum]=0;
		int m;
		for(m=end;m>=0;m--)
		{
			sum2+=(str[m]-'0');
			if(sum2<=maxsum)
			{
				dp[end][maxsum]+=numg(m-1,sum2);
			}
		}
	}
	return dp[end][maxsum];
}

int main()
{
	
	scanf("%s",str);
	len=strlen(str);
	//printf("%s\n",str);
	int cnt=1;
	
	while(str[0]!='b')
	{
		memset(dp,-1,sizeof(dp));
		//construct();
		int sum1=0;
		int ans=0;
		cout<<cnt<<". "<<numg(len-1,260)<<endl;
		//cout<<ans+1<<endl;
		scanf("%s",str);
		len=strlen(str);
		cnt++;
	}
	return 0;
}
