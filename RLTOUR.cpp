#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int h[n], c[n];
		int ans[501]={0};
		for(int i=0; i<n; i++)scanf("%d", &h[i]);
		for(int i=0; i<n; i++) scanf("%d", &c[i]);
		sort(h, h+n);
		for(int i=0; i<n; i++)
		{
			for(int j=n-1;j>=0;j--)
			{
				if(c[j]==j&&ans[j]==0)
				{
					ans[j]=h[i];
					for(int k=j+1;k<n;k++)
					{
						c[k]++;
					}
					break;
				}
			}
		}
		for(int i=0; i<n; i++) printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}

