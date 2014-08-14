#include <algorithm>
#include <iostream>

#define inf 1000000000
#define MAXN 2000

using namespace std;

 int n;
    
    
int a[MAXN];

int find(int sum)
{
	int start=0,end=n-1;
	int mid=(start+end)/2;
	while(start<=end)
	{
		mid=(start+end)/2;
		
		if(a[mid]>sum)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}
	if(a[mid]<=sum)
	return mid+1;
	else
	return mid;
}

int main()
{
   
   int x,pairs;
    while (scanf("%d", &n) && n!=0) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        pairs=0;
        for(int i=0;i<n;i++)
        {
        	for(int j=i+1;j<n;j++)
        	{
        		x=find(a[i]+a[j]);
        		pairs+=n-x;
        	}
        }
        printf("%d\n", pairs);
    }
    return 0;
}
    
