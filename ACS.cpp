#include<iostream>
using namespace std;

int main()
{
	int x,y;
	char c;
	char d[10];
	int atr[9352],atc[5779],rat[9339],cat[5779];
	for(int i=0;i<1234;i++)
	{
		atr[i]=i;
		rat[i]=i;
	}
	
	for(int i=0;i<5678;i++)
	{
		atc[i]=i;
		cat[i]=i;
	}
	
	while(scanf("%s",d)==1)
	{
		c=d[0];
		if(c=='R')
		{
			scanf("%d %d",&x,&y);
			x--;
			y--;
			int rx=atr[x];
			atr[x]=atr[y];
			rat[atr[y]]=x;
			atr[y]=rx;
			rat[rx]=y;
		}
		else if(c=='C')
		{
			scanf("%d %d",&x,&y);
			x--;
			y--;
			int cx=atc[x];
			atc[x]=atc[y];
			cat[atc[y]]=x;
			atc[y]=cx;
			cat[cx]=y;
		} 
		else if(c=='Q')
		{
			scanf("%d %d",&x,&y);
			x--;
			y--;
			int a=atr[x];
			int b=atc[y];
			unsigned long long v=(a)*5678+b+1; 
			printf("%llu\n",v);
		}
		else if(c=='W')
		{
			scanf("%d",&x);	
			int a=(x-1)/5678;
			int b=x-(a)*5678-1;
			printf("%d %d\n",rat[a]+1,cat[b]+1);
		}
	}
	return 0;
}
