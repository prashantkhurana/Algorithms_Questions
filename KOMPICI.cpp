#include <stdio.h>
#include<iostream>
#include <string.h>
using namespace std;
typedef long long LL;

int n;
int count[1<<10];
char num[20];
int b_rep;
long long int res=0;

int main() {
	scanf("%d", &n);
	memset(count,0,sizeof(count));
	for (int i = 0; i < n; i++) 
	{
		scanf("%s",&num);
		b_rep=0;
		for(int i=0;i<strlen(num);i++)
		{
			b_rep=b_rep|(1<<(num[i]-'0'));
		}
		count[b_rep]++;
	}
	res=0;
	for(int i=0;i<(1<<10);i++)
	{
		if(count[i]>0)
		for(int j=i;j<(1<<10);j++)
		{
			if(i==j)
			{
				res=res+((count[j]-1)*(count[j])/2);
			}
			else if(i&j)
			{
				if(count[j]>0)
				res+=(count[i]*count[j]);
			}
		}
	}
	printf("%lld\n",res);
	return 0;
}
