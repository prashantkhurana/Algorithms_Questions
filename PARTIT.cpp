#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int count;
int arr[12];
unsigned long long dp[221][11];
int n1;

void init()
{
	for(int i=1;i<221;i++)
	dp[i][0]=0;
	dp[0][0]=1;
	
	for(int i=1;i<221;i++)
	{
		for(int j=1;j<=10&&j<=i;j++)
		{
			dp[i][j]=dp[i-1][j-1]+dp[i-j][j];
		}
	}
}

//	if(n==0 && m!=0)
//	return -1;
//	else if(n==0 && m==0)
//	{
//		count++;
//		return m;
//	}

//		int x=dp[m-1][n-1]
//		if(x>=k)
//		{
//			arr[pos]=1;
//			printf("1 ");
//			solve(m-1,n-1,k,pos+1);
//		}
//		else

void solve(int m, int n, int k, int pos)
{
	if(n==1)
	arr[pos]=m;

	else
		{
			long long x=0;
			for(int i=1;i<=m;i++)
			{
				
				x=dp[m-i-((i-1)*(n-1))][n-1];
				if(k-x<=0)
				{
					arr[pos]=i;
					//printf("%d ",i);
					solve(m-i-((i-1)*(n-1)),n-1,k,pos+1);
					if(i>1)
					for(int l=pos+1;l<n1;l++)
					arr[l]+=(i-1);
					break;
				}
				else
				{
					k=k-x;
				}
			}	
		}
		
		
//		if(x!=-1)
//		dp[m][n]=i*pow(10,n-1)+x;
//		else
//		dp[m][n]=x;
//		
//		if(x!=-1 && count ==k)
//		return dp[m][n];
//		if(x!=-1 && count !=k)
//		return -1;
//	

}


int main()
{
	int t,m1,k1;
	scanf("%d",&t);
	memset(dp,0,sizeof(dp));
	init();
	
	while(t--)
	{
		count=0;
		scanf("%d",&m1);
		scanf("%d",&n1);
		scanf("%d",&k1);
		memset(arr,0,sizeof(arr));
		solve(m1,n1,k1,0);
		for(int z=0;z<n1;z++)
		if(z!=n1-1)
		printf("%d ",arr[z]);
		else
		printf("%d",arr[z]);
		printf("\n");
//		for(int i=0;i<n1;i++)
//		{
//			printf("%d ",arr[i]);
//		}
	}
	return 0;
}
