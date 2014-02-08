#include<stdio.h>
#include<iostream>

using namespace std;
int count=0;
int start[1000],end[1000];
int sum,n;


void findnumways(int index, int local_sum)
{
	if(index>n)
	{
		if(local_sum==sum)
		count++;
	}
	else
	for(int i=start[index];i<=end[index];i++)
	{
		findnumways(index+1,local_sum+i);
	}
}


int main()
{
	scanf("%d %d",&n,&sum);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&start[i], &end[i]);
	}
	findnumways(1,0);
	printf("%d",count);
	return 0;
}

