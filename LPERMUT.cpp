#include<iostream>
using namespace std;

int main()
{
	int n;
	int a[100001];
	int ans[100001];
	int map[100001]={0};
	int start=0,end=0,len=0,sum=0,j=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		if(map[a[i]]==0)
		{
			map[a[i]]=1;
			ans[end++]=a[i];
		}
		else
		{
			sum=0;
			j=0;
			while(ans[start]!=a[i])
			{
				sum+=ans[start];
				map[ans[start]]--;
				start++;
				j++;
			}
			sum+=ans[start];
			map[ans[start]]--;
			start++;
			j++;
			for(int v=start;v<end;v++)
			{
				sum+=ans[v];
				j++;
			}
			if(sum==(j*(j+1)/2))
			{
				if(j>len)
				len=j;
			}
			map[a[i]]++;
			ans[end++]=a[i];
		//	for(int y=start;y<end;y++)
			//cout<<ans[y]<<" ";
			//cout<<endl;
		}
	}
	sum=0;
	j=0;
	for(int v=start;v<end;v++)
			{
				sum+=ans[v];
				j++;
			}
	if(sum==(j*(j+1)/2))
			{
				if(j>len)
				len=j;
			}
	printf("%d\n",len);
	return 0;
}
