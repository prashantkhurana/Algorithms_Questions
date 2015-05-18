#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
	int t,at,bt;
	int a[100008];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&at,&bt);
		queue<int> q;
		for(int i=0;i<at;i++)
		{
			scanf("%d",&a[i]);
		}
		int ans=0,prevans=0;
		int i=0;
		int sum=0,minsum=10000009;
		while(i<at)
		{
			while(sum<=bt&&i<at)
			{
				q.push(a[i]);
				sum+=a[i];
				i++;
			}
			prevans=ans;
			if(sum>bt)
			{
				ans=max(ans,(int)q.size()-1);
				if(ans!=prevans)
				minsum=sum-a[i-1];
				else if (ans==((int)q.size()-1))
				{
					minsum=min(minsum,sum-a[i-1]);
				}
			}
			else
			if(i==at)
			{
				ans=max(ans,(int)q.size());
				if(ans!=prevans)
				minsum=sum;
				else if(ans==(int)q.size())
				minsum=min(minsum,sum);
			}
			while(sum>bt)
			{
				sum-=q.front();
				q.pop();
			}
		}
		printf("%d %d\n",minsum,ans);
	}
	return 0;
}
