#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
int n,t,i,j,k,time,h,m,s,rear,front,ans,max;
int hr[20000],min[20000], sec[20000],arr[20000];
char ch[10];

scanf("%d",&t);
for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	for(j=0;j<n;j++)
		{
		scanf("%s",ch);
		k=0;
		hr[j] = min[j] = sec[j] = 0;
		while(ch[k]!=':')
			{
			hr[j] = hr[j]*10 + (ch[k] - '0');
			k++;
			}
		k++;
		while(ch[k]!=':')
			{
			min[j] = min[j]*10 + (ch[k] - '0');
			k++;
			}
		k++;
		while(ch[k]!='\0')
			{
			sec[j] = sec[j]*10 + (ch[k] - '0');
			k++;
			}	
		arr[j] = hr[j]*3600 + min[j]*60 + sec[j];
		}
	scanf("%d",&time);
	sort(arr,arr+n);
	rear = 0;
	front = 0;
	ans=0;
	while(front<n)
		{
		if(arr[front]>=arr[rear]+time)
			{
				front++;
			//	ans++;
				rear++;
			}
		else
			{
			front++;
			ans++;
			}
		}
	printf("Case %d: %d\n",i+1,ans);
	}
return 0;
}
