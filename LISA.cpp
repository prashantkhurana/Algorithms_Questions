#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<map>
#include<stdio.h>
#include<limit.h>
using namespace std;

string s;
int dp1[102][102],dp2[102][102];


int main()
{
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		cin>>s;
		int n=s.length();
		//cout<<n;
		for(int i=0;i<n;i=i+2)
		{
			dp1[i][i]=s[i]-'0';
			dp2[i][i]=s[i]-'0';
		}
		for(int l=2;l<s.length();l=l+2)
		{
			for(int i=0;i<s.length()-l;i=i+2)
			{
				int j=i+l;
				int ans1=0,ans2=INT_MAX;
				for(int k=i;k<j;k=k+2)
				{
					if(s[k+1]=='+')
					if(ans1<dp1[i][k]+dp1[k+2][j])
					{	
						ans1=dp1[i][k]+dp1[k+2][j];
					}
					if(s[k+1]=='*')
					if(ans1<dp1[i][k]*dp1[k+2][j])
					{
						ans1=dp1[i][k]*dp1[k+2][j];
					}
					if(s[k+1]=='+')
					if(ans2>dp2[i][k]+dp2[k+2][j])
					{	
						ans2=dp2[i][k]+dp2[k+2][j];
					}
					if(s[k+1]=='*')
					if(ans2>dp2[i][k]*dp2[k+2][j])
					{
						ans2=dp2[i][k]*dp2[k+2][j];
					}
				}
				dp1[i][j]=ans1;
				dp2[i][j]=ans2;
				
			}

	}
	cout<<endl<<dp1[0][n-1]<<" "<<dp2[0][n-1]<<endl;
}
	
	
	return 0;
}
