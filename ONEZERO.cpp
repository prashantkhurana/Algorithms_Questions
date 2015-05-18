#include<iostream>
#include<queue>
#include<stdlib.h>
#include<string.h>
using namespace std;


int parent[20005];
int n;


void print(int topa)
{
	if(topa==1)
	{
		cout<<1;
		return;
	}
	//return;
	int top=parent[topa];
	int left=top*10%n;
	int right=((top*10)%n+1)%n;
	if(left==topa)
	{
		print(top);
		cout<<0;
	}
	else
	{
		print(top);
		cout<<1;
	}
}



void ansrt()
{
	//return;
	std::queue<int>q;
	memset(parent,0,sizeof(parent));
	int x=1%n;
	q.push(1);

	while(q.size()!=0)
	{
		int top=q.front();
		q.pop();
		if(top==0)
		{
			print(top);
		}
		else
		{
			int left=top*10%n;
			if(parent[left]==0)
			{
				parent[left]=top;
				q.push(left);
			}
			int right=((top*10)%n+1)%n;
			if(parent[right]==0)
			{
				parent[right]=top;
				q.push(right);
			}
		}
	}
}


int main()
{
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		cin>>n;
		ansrt();
		cout<<endl;
	}
	return 0;
}


