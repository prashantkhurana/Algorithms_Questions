#include<stdio.h>

int main()
{
int t,n,i,j,k,in[1001],out[1001];
int count;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d",&n);
	int max=0;
	int max_index;
	for(j=1;j<=n;j++)
	{
		scanf("%d %d",&in[j],&out[j]);
		if(in[j]>max)
		{
			max=in[j];
			max_index=j;
		}
	}
	int count=0;		
	for(j=1;j<=n;j++)
	{
		if(max<=out[j]&&j!=max_index)
		{
			printf("-1\n");
			count=1;
			break;
		}
	}
		if(count==0)
		printf("%d\n",max_index);
	}
return 0;
}
