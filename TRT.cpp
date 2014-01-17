#include<cstdio>
#include<algorithm>
#define MAX 2100 

using namespace std ;

#define get getchar_unlocked

int n;
int x[3000];
int ans[3000][3000];
int sum[3000][3000];
int solve(int  s, int e) 
{
	if(ans[s][e]!=0)
	return ans[s][e];
	else if(s==e)
	{
		ans[s][s]=x[s];
		sum[s][e]=x[s];
		return x[s];
	}
	else
	{
		ans[s+1][e]=solve(s+1,e);
		ans[s][e-1]=solve(s,e-1);
		ans[s][e]=max(1*x[s]+ans[s+1][e]+sum[s+1][e],1*x[e]+ans[s][e-1]+sum[s][e-1]);
		sum[s][e]=x[s]+sum[s+1][e];
		return ans[s][e];
	}
	
}

int main()
{
	int i ;
	scanf("%d",&n);
	
	
	for( i = 0 ; i < n ; i++ )
		scanf("%d",&x[i]);
	for( i = 0 ; i < n ; i++ )
	for(int j=0;j<n;j++){
		ans[i][j]=0;
		sum[i][j]=0;
	}
				i=1;
	printf("%d\n",solve(0,n-1));
	
	return 0 ;
	
}
