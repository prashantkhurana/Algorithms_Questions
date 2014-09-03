#include<iostream>
#include<stdio.h>
using namespace std;

int a[1000007];

int no=1,size=1,i=0;
int j,curr;
void init()
{
	a[0]=1;
	j=0;
	no=1;
	i=1;
	while(i<1000007)
	{
		curr=i;
		size=a[j];
		no++;
		while(i<curr+size)
		{
			a[i++]=no;
		}
		j++;
	}
}
int main()
{
	int cases,n;
init();
scanf("%d",&cases);
for(i=1;i<=cases;i++)
{
	scanf("%d",&n);
	printf("Case #%d: %d\n",i,a[n-1]);
}
return 0;
}



