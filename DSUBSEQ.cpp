#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	char s[100009];
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		long long sum[n],last[26],dp[n];
		sum[0]=1;
		dp[0]=1;
		memset(last,-1,sizeof(last));
		last[s[0]-'A']=0;
		for(int i=1;i<n;i++)
		{
			if(last[s[i]-'A']!=-1)
			{
				if((last[s[i]-'A']-1)>=0)
			dp[i]=(sum[i-1]-sum[last[s[i]-'A']-1]+1000000007)%1000000007;
			else
			dp[i]=(sum[i-1]+1000000007)%1000000007;
			}
			
			else
			dp[i]=(sum[i-1]+1+1000000007)%1000000007;
			sum[i]=(sum[i-1]+dp[i]+1000000007)%1000000007;
			last[s[i]-'A']=i;
		}
		printf("%lld\n",(sum[n-1]+1+1000000007)%1000000007);
	}
	return 0;
}
