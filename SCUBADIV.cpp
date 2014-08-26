#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int maxint = 0x3f3f3f3f-801;

int oxr, nir, n, t, cs;
int ni[1002], ox[1002], w[1002];
int dp[1002][22][80]={-1};

int solve(int i, int oxr, int nir) 
{
	if(oxr<0) oxr=0;
	if(nir<0)nir=0;
	if(oxr<=0 && nir<=0)
	return 0;
	if(i<0)
	return maxint;
	if(dp[i][oxr][nir]!=-1)
	return dp[i][oxr][nir];
	//else if(i<0)
	//return INT_MAX;
	else
	{
		int x=solve(i-1,oxr,nir);
		int y= solve(i-1,oxr-ox[i],nir-ni[i])+w[i];
		return dp[i][oxr][nir]=min(x,y);
	}
}



int main() {
	scanf("%d", &t);
	while(t--) {
		memset(dp,-1,sizeof(dp));
		scanf("%d %d", &oxr, &nir);
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		scanf("%d %d %d", &ox[i], &ni[i], &w[i]);
		printf("%d\n", solve(n-1, oxr, nir));
	}
	return 0;
}
