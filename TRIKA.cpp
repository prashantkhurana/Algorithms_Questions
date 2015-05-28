#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<map>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
	int n,m,a,b;
	int pow[21][21];
	int ans[21][21];
	
	
	scanf("%d %d",&n,&m);
	scanf("%d %d",&a,&b);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&pow[i][j]);
		}
	}
		int temp=0;
		for(int i=m-1;i>=0;i--)
		{
			ans[n-1][i]=temp+pow[n-1][i];
			temp+=pow[n-1][i];
		//	cout<<ans[n-1][i];
		}
		
		for(int i=n-2;i>=0;i--)
		{
			for(int j=m-1;j>=0;j--)
			{
				if(j!=m-1)
				ans[i][j]=pow[i][j]+min(ans[i+1][j],ans[i][j+1]);
				else
				ans[i][j]=pow[i][j]+ans[i+1][j];
				
		//	cout<<ans[i][j]<<endl;
			}
		}
	
	ans[a-1][b-1]-=pow[a-1][b-1];
	
	if(pow[a-1][b-1]>=ans[a-1][b-1])
	cout<<"Y"<<" "<< pow[a-1][b-1] - ans[a-1][b-1]<<endl;
	else
	cout<<"N"<<endl;
	return 0;
}
