#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;


char list[30][100];
float inf=0;
float dist[30][30];
float final[30][30];
int n,m;


void floydwarshall()
{
int i,j,k;

for(k=1;k<=n;k++)
	{
	for(i=1;i<=n;i++)
		{
		for(j=1;j<=n;j++)
			{
			if(dist[i][k]*dist[k][j]>dist[i][j])
				dist[i][j]=dist[i][k]*dist[k][j];	
			}
		}	
	}

}




int main()
{
int i,x,y,j,c=1,flag;
string curr;
float val;

scanf("%d",&n);

while(n!=0)
	{
		map<string,int> m_map;
	for(i=1;i<=n;i++)
		{
		cin>>curr;
		m_map.insert(std::pair<string,int>(curr,i));
		}

	scanf("%d",&m);
	
	 for(x=1;x<=n;x++)
                {
                for(y=1;y<=n;y++)
			{
		
				dist[x][y]=0;
			}
                }


	for(i=1;i<=m;i++)
		{	
		cin>>curr;
		int x=m_map.find(curr)->second;
		scanf("%f",&val);
		cin>>curr;
		int y=m_map.find(curr)->second;
		dist[x][y]=val;	
		}


	floydwarshall();


	flag=0;
	for(x=1;x<=n;x++)	
		{
		if(dist[x][x]>1)
			{
			flag=1;
			break;
			}
		}

	if(flag==1)
		printf("Case %d: Yes\n",c);

	else
		printf("Case %d: No\n",c);

	scanf("%d",&n);	
	c++;
	}

return 0;
}
