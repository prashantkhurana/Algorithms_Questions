#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
int t,i,j,n,arr[100005];
long long  int sum[100005];
long long int tmp,min1;
scanf("%d",&t);
sum[0]=0;
while(t--)
	{
	scanf("%d",&n);
	//sum=0;
	//min1=100000002;
	//if(n==2)
	//scanf("%d",min1);
		for(i=1;i<=n;i++)
		{
		scanf("%d",&arr[i]);
		sum[i]=sum[i-1]+arr[i];
		}
		min1=sum[n]-arr[1];
			for(int i=2;i<=n;i++)
		{
			int leavei=sum[n]-arr[i]+min(sum[i-1],sum[n]-sum[i]);
			if(leavei<min1)
			min1=leavei;
		}
	
		
		
		printf("%d\n",min1);	
	}
return 0;
}
