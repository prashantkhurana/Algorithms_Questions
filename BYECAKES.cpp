#include<iostream>
#include<stdio.h>
using namespace std;


int ceil(int a, int b)
{
	if(a%b==0)
	return a/b;
	else
	return a/b+1;
}
int main()
{
	int e,f,s,m,e1,f1,s1,m1;
	int cake,a[8];
	while(1)
	{
		for(int i=0;i<8;i++)
		scanf("%d",&a[i]);
		//scanf("%d %d %d %d %d %d %d %d",&e,&f,&s,&m,&e1,&f1,&s1,&m1);
		if(a[0]==-1)
		break;
		else
		{
			cake=0;
			for(int i=0;i<=3;i++)
			{
				if(cake<ceil(a[i],a[i+4]))
				cake=ceil(a[i],a[i+4]);
			}
			int ans[8]={0};
			for(int i=0;i<=3;i++)
			{
				if(a[i]<cake*a[i+4])
				ans[i]=cake*a[i+4]-a[i];
			}
			for(int i=0;i<=3;i++)
			printf("%d ",ans[i]);
			printf("\n");
		}
		
	}
	return 0;
}
