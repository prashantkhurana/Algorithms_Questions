#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 1009

int howmuch[maxn][maxn],a[maxn];
int n;


int winby(int s, int e)
{
	if(howmuch[s][e]!=-1)
	return howmuch[s][e];
	else
	{
		int x=-1;
		int y=-1;
		//picking the 1st
		//if(s!=e)
		{
			if(a[s+1]>=a[e])
			{
				if(s+2<e)
				{
					x=howmuch[s+2][e]=winby(s+2,e);
					x+=a[s]-a[s+1];
				}
				else
				{
					x=a[s]-a[s+1];
				}
			}
			else
			{
				if(e-1>s)
				{
					x=howmuch[s+1][e-1]=winby(s+1,e-1);
					x+=a[s]-a[e];
				}
				else
				{
					x=a[s]-a[e];
				}
			}
		}
		//pick last
		{
			if(a[s]>=a[e-1])
			{
				if(s+1<e-1)
				{
					y=howmuch[s+1][e-1]=winby(s+1,e-1);
					//y+=a[e]-a[s];
				}
				if(y==-1)
				y=0;
				y+=a[e]-a[s];
			}
			else
			{
				if(s<e-2)
				{
					y=howmuch[s][e-2]=winby(s,e-2);
				
				}
				if(y==-1)
				y=0;
				y+=a[e]-a[e-1];
			}
		}
		return max(x,y);
	}
	
}

int main()
{
	int num=0;
	while(scanf("%d",&n))
	{
		num++;
		if(n==0)
		break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(howmuch,-1,sizeof(howmuch));
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",num,winby(0,n-1));
	}
}
