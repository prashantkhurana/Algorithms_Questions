#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct order
{
	int start;
	int finish;
	int price;
};
typedef struct order order;

bool compare(order const& a,order const& b)
{
	if(a.finish!=b.finish)
	return a.finish<b.finish;
	return a.start<b.start;
}


int find_order(order o[], int f,int start_s, int end_s)
{
	while(start_s<=end_s)
	{
		int mid=(start_s+end_s)/2;
		if(o[mid].finish==f)
		{
			if(o[mid+1].finish!=f)
			return mid;
			else 
			start_s=mid+1;
		}
		else if(o[mid].finish<f)
		start_s=mid+1;
		else
		end_s=mid-1;
	}
	return end_s;
}

int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		order o[n];
		int d;
		int max_dp[n];
		memset(max_dp,0,sizeof(max_dp));
		for(int j=0;j<n;j++)
		{
			scanf("%d %d %d",&o[j].start,&d,&o[j].price);
			o[j].finish=o[j].start+d;
		}
		sort(o,o+n,compare);
		for(int i=0;i<n;i++)
		{
			if(!i)
			max_dp[i]=o[i].price;
			else
			{
				int b_o=find_order(o,o[i].start,0,n-1);
				if(b_o!=-1)
				max_dp[i]=max(max_dp[i-1],max_dp[b_o]+o[i].price);
				else
				max_dp[i]=max(max_dp[i-1],o[i].price);
			}
		}
		printf("%d\n",max_dp[n-1]);
	}
	
}
