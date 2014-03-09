#include<iostream>
using namespace std;

int main()
{
	int n,a1=0,a2=0,a3=0,ans=0;
	int c1,c2;
	char op;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%c%d",&c1,&op,&c2);
		if(c1==3)
		{
			a3++;
		}
		else if (c2==4)
		{
			a1++;
		}
		else
		a2++;
	}
	a1=a1-a3;
	ans=a2/2;
	a2=a2%2;
	if(a1>0)
	{
		a1=a1-2*a2;
	}
	if(a1>0)
	{
		if(a1%4==0)
		ans=ans+(a1/4);
		else
		ans=ans+(a1/4)+1;
	}
	ans+=a2+a3;
	printf("%d\n",ans+1);
	return 0;	
}
