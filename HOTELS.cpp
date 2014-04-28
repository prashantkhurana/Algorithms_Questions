#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,m,a[300009];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int sum=0,i=0,j=0;
	int temp=0;
	for(i=0;i<n;i++)
	{
		temp+=a[i];
		if(temp==m)
		{
			printf("%d",temp);
			return 0;
		}
		else if(temp>sum && temp<=m)
		{
			sum=temp;
		}
		else 
		if(temp>m)
		{
			while(j<=i&&temp>m)
			{
				temp-=a[j++];
			}
			if(temp==m)
			{
				printf("%d",m);
				return 0;
			}
			else if(temp<m && temp>sum)
			sum=temp;
		}
	}
	printf("%d",sum);
	return 0;
}
