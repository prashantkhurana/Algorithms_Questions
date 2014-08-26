#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int main()
{
	int t,n,m,x;
	scanf("%d",&t);
	int a[101];
	
	for(int i=0;i<t;i++)
	{
		std::queue<std::pair<int,int> > queue;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			queue.push(std::make_pair(a[i],i));
		}
		sort(a,a+n,std::greater<int>());
		int i=0;
		int b=1;
		while(queue.size())
		{
			b++;
			std::pair<int,int> x=queue.front();
				if(x.first!=a[i])
			{
				queue.pop();
				queue.push(x);
			}
			else
			{
				queue.pop();
				i++;
				if(x.second==m)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
