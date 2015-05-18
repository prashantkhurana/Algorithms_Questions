#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int n,f,t;

int a[10005];


int check(double mid)
{
	int p=n-1;
	int g=0;
	while(g<f)
	{
		if(a[p]>=mid)
		{
			g+=(a[p]/mid);
		}
		else
		{
			return 0;
		}
		p--;
	}
	
	return 1;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&f);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			a[i]*=a[i];
		}
		f++;
		sort(a,a+n);
		double start=0;
		double end=a[n-1];
		while(start<(end- (1e-6)))
		{
			double mid=(start+end)/2;
			if(check(mid))
			{
				start=mid;
			}
			else
			{
				end=mid;
			}
		}
		printf("%f\n",start*3.14159265358979323846264338327950);
	}
	return 0;
}
