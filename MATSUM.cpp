#include<iostream>
#include<string.h>
using namespace std;
#define max 1030
int t[max][max],f[max][max];
int N;
int read(int x1, int y1)
{
	int sum1=0;
	int y;
	while(x1>0)
	{
		y=y1;
		while(y>0)
		{
			sum1+=t[x1][y];
			y-=(y&-y);
		}
		x1-=(x1&-x1);
	}
	return sum1;
}


void updatey(int x, int y, int val)
{
	while(y<=N)
	{
		t[x][y]+=val;
		y+=(y&-y);
	}
}

void update(int x,int y, int val)
{
	while(x<=N)
	{
		updatey(x,y,val);
		x+=(x&-x);
	}
}

int main()
{
	int T,x,y,num,x1,x2,y1,y2;
	char s[4];
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<max;i++)
		{
			for(int j=0;j<max;j++)
			{
				t[i][j]=0;
				f[i][j]=0;
			}
		}
		scanf("%d",&N);
		
			while(scanf("%s",s))
		{
		if(s[1]=='E')
			{
				scanf("%d %d %d",&x,&y,&num);
				int u=num-f[x+1][y+1];
				update(x+1,y+1,-f[x+1][y+1]);
				update(x+1,y+1,num);
				f[x+1][y+1]=num;
			}
			else if(s[1]=='U')
			{
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				int v1 = read(x2+1,y2+1);
				int v2 = read(x2+1,y1);
				int v3 = read(x1,y1);
				int v4 = read(x1,y2+1);
				printf("%d\n",v1-v2-v4+v3);
			}
			else 
			break;
		}
	}
}
