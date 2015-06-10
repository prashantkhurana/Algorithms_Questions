#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;


int t, n, q, a[1000008],m[1000008][21];
void preprocess()
{
	for(int i=0;i<n;i++)
		m[i][0]=a[i];
	int logn=floor(log2(n));
	//cout<<"logn is :"<<logn<<endl;

	for(int j=1;j<=logn;j++)
	{
		for(int i=0;i<n;i++)
		{
			if((i+(1<<j))>n)
				continue;
			else
			{
				m[i][j]=min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
			}
		}
	}
	//cout<<"m is:"<<endl;
	for(int j=0;j<=logn;j++)
	{
		for(int i=0;i<n;i++)
		{
		//	cout<<m[i][j];
		}
		//cout<<endl;
	}
}
int main()
{
	scanf("%d",&t);
	int p=1;
	//cout<<"t:"<<t<<endl;
	while(t--)
	{
		scanf("%d %d",&n,&q);
		//cout<<"n and q:"<<n<<q<<endl;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		//cout<<"array is:";
		for(int i=0;i<n;i++)
		{
			//cout<<a[i];
		}
		//cout<<endl;
		preprocess();
		int c,d;

		printf("Scenario #%d:\n",p);
		p++;
		for(int i=0;i<q;i++)
		{
			scanf("%d %d",&c,&d);
			//cout<<"c and d are:"<<c<<d;
			if(c>d)
			{
				int temp=c;
				c=d;
				d=temp;
			}
			int logcd=floor(log2(d-c+1));
			int ans=min(m[c-1][logcd],m[d-(1<<logcd)][logcd]);
			printf("%d\n",ans);
		}
	}
}
