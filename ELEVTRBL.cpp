#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

int visited[1000050];
int getMin(int f, int s, int g, int u, int d)
{ 
	int ans=0;
	queue<int> q;
	q.push(s);
	visited[s]=0;
	while(!q.empty())
	{
		s=q.front();
		ans=visited[s];
		if(s==g)
		return ans;
		q.pop();
		if((s+u)<=f && visited[s+u]==-1)
		{
			q.push(s+u);
			visited[s+u]=ans+1;
		}
		if((s-d)>=1 && visited[s-d]==-1)
		{
			q.push(s-d);
			visited[s-d]=ans+1;
		}
	}
	return -1;	
	
}


int main()
{
long int f,s,g,u,d;
int i;
memset(visited,-1,sizeof(visited));
scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);
int x=getMin(f,s,g,u,d);
if(x!=-1)
	printf("%d\n",x);
else
	printf("use the stairs\n");
return 0;
}
