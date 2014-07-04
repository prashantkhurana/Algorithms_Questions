#include<iostream>
using namespace std;

int main()
{
	int k,l,n,m;
	bool win[1000005];
	scanf("%d %d %d",&k,&l,&n);
	for(int i=1;i<=1000000;i++)
	{
		if(i-1==0 || i-k==0 || i-l==0||win[i-1]==false)
		win[i]=true;
		else if ( i-l>=0 && win[i-l]==false )
		win[i]=true;
		else if(i-k>=0 && win[i-k]==false)
		win[i]=true;
		else
		win[i]=false;
	}
	while(n--)
	{
		scanf("%d",&m);
		printf("%c",(win[m]==true)?'A':'B');
	}
	return 0;
}
