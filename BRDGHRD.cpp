#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct point
{
	int first;
	int second;
};
struct point a[100000];
typedef struct point point;

bool point_sorter(point const& lhs, point const& rhs) {
    if (lhs.first != rhs.first)
        return lhs.first < rhs.first;
    return lhs.second < rhs.second;
}
int find(int c[], int num, int start, int end)
{
	if(start>end)
	return start;
	else
	{
		int mid=(start+end)/2;
		if(c[mid]==num)
		return mid+1;
		if(c[mid]>num)
		return find(c,num,start,mid-1);
		else
		return find(c,num,mid+1,end);
	}
}
int lis(point a[],int n)
{
	int size=0,size_virtual=0;
	int c[100000];
	for(int i=0;i<n;i++)
	{
		int x=find(c,a[i].second,1,size);
		//if(x<=size && c[x]==a[i].second)
		//size_virtual++;
		c[x]=a[i].second;
		if(x>size)
		{
			size=x;
		//	size_virtual;
		}
	}
	return size;
}
int main()
{
int t,i,j,n;
long int res;
scanf("%d",&t);
for(i=0;i<t;i++)
	{
	
	scanf("%d",&n);

	for(j=0;j<n;j++)
		scanf("%d",&a[j].first);
	for(j=0;j<n;j++)
                scanf("%d",&a[j].second);
	sort(a,a+n,point_sorter);
	res=lis(a,n);
	printf("%ld\n",res);
	}
return 0;
}
