#include<stdio.h>

int main()
{
int t,n,m,i,j,a[10001],b[10000],inc,inb,curb,curc,set;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	scanf("%d %d",&n,&m);
	inc=1,curc=1,set=1;
	inb=n-1,curb=n-1;
	scanf("%d",&a[0]);
	for(j=1;j<m;j++){
		scanf("%d",&a[j]);
		if((a[j]-a[j-1])>0)
		{
			curc=curc+a[j]-a[j-1];
			curb=curb-a[j]+a[j-1];
			if(curb<0)
			{
				set=0;
				printf("-1\n");
				for(int p=j+1;p<m;p++)
				scanf("%d",&a[j]);
				break;
			}
		}
		else if((a[j]-a[j-1])<0)
		{
			curc=curc-a[j-1]+a[j];
			if(curc<=0)
			{
				inc=1-curc+inc;
				inb=n-inc;
				curc=1;
				curb=n-1;
				if(inb<0)
				{
					set=0;
					for(int p=j+1;p<m;p++)
				scanf("%d",&a[j]);
				printf("-1\n");
				break;
				}
			}
			else
			{
				curb=n-curc;
			}
		}
		else if((a[j]-a[j-1])==0)
		{
			curc=curc-1;
			n--;
			if(curc<=0)
			{
				inc=1-curc+inc;
				inb=n-inc;
				curc=1;
				curb=n-1;
				if(inb<0)
				{
					set=0;
					for(int p=j+1;p<m;p++)
				scanf("%d",&a[j]);
				printf("-1\n");
				break;
				}
			}
			else
			{
				curb=n-curc;
			}
		}
	}
	if(set)
	printf("%d\n",inc);
}

return 0;
}
