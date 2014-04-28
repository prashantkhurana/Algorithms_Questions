#include<iostream>
#include<cstring>
#include<queue>
#include<stdlib.h>
using namespace std;

#define N 10000
#define sqrt(N) 1000

int primes[N];


void uncheck(int p)
{
	int x=2*p;
	while(x<=N)
	{
		primes[x]=0;
		x=x+p;
	}
}


void generatePrimes()
{
	for(int i=1;i<=N;i++)
	primes[i]=1;
	for(int i=2;i<=sqrt(N);i++)
	{
		if(primes[i])
		{
			uncheck(i);
		}
	}
}


int bfs(int a,int b)
{
	if(a==b)
	return 0;
	int visited[N];
	memset(visited,0,sizeof(visited));
	queue<int>q;
	q.push(a);
	int c,i,j,h,u;
	int d[N];
	d[a]=0;
	char temp[6];
	int temp1;
	while(!q.empty())
	{
		
		u=q.front();
		visited[u]=1;
		q.pop();
		for(i=0;i<4;i++)
		{
			for(j=0;j<=9;j++)
			{
				if(i==0 && j==0)
				continue;
				else
				{
					snprintf(temp,sizeof(temp),"%d",u);
					temp[i]='0'+j;
					temp1=atoi(temp);
					if(!visited[temp1] && primes[temp1])
					{
						q.push(temp1);
						d[temp1]=d[u]+1;
						visited[temp1]=1;
						if(temp1==b)
						return d[temp1];
					}		
				}
			}	
		}
	}
}


int main()
{
	generatePrimes();
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",bfs(a,b));
	}
	return 0;
}

