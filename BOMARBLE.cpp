#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int n,s,i;
	scanf("%d",&n);
	while(n!=0)
	{
		int lines=5,dots=5;
		for(int i=2;i<=n;i++)
		{
			dots+=lines+2;
			lines+=3;
		}
		printf("%d\n",dots);
		scanf("%d",&n);
	}
	return 0;
}

