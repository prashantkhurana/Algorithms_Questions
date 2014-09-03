#include<iostream>
#include<map>
#include<vector>
using namespace std;


int main()
{
	int t,n;
	int a[102];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		map<int,int> m;
		int ct=0;
		vector<int> num;
		for(int i=1;i<=n;i++)
		{
			int count=ct;
			int p=0;
			for(int j=0;j<count;j++)
			{
				int x=num[j]+a[i];
				if(m.find(x)==m.end())
				{
					m[x]=1;
					num.push_back(x);
					ct++;
				}
			}
			if(m.find(a[i])==m.end())
			{
				m[a[i]]=1;	
				num.push_back(a[i]);
				ct++;
			}
			
		}
		int sum=0;
		for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
			{
				sum+=i->first;
			}
		printf("%d\n",sum);
	}
}
