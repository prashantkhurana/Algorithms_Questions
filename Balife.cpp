#include<stdio.h>

int num[9000];


int main()
{
int i,j,n,sum,one,res,ch,rounds;
float left[9000],right[9000];

scanf("%d",&n);

while(n!=-1)
	{
	sum=0;
	for(i=0;i<n;i++)
		{
		scanf("%d",&num[i]);
		sum+=num[i];		
		}
	
	if(sum%n!=0)
		printf("-1\n");

	else
		{
		one = sum/n;
		rounds=0;
		for(int i=0;i<n;i++)
		{
//			if(num[i]>one)
//			num[i]-=rounds;
//			if(num[i]<one)
//			num[i]-=rounds;
//			
			
			if(num[i]!=one)
			{
				if(num[i]>one)
				{
					if((num[i]-one)>rounds)
					{
						num[i+1]+=(num[i]-one);
						num[i]=num[i]-rounds;
						rounds+=(num[i]-one);
						num[i]=one;
					}
					else if((num[i]-one)<=rounds)
					{
						//num[i]=num[i]-rounds;
						num[i+1]+=(num[i]-one);
						//rounds+=(num[i]-one);
						num[i]=one;
					}
				}
				if(num[i]<one)
				{
					if((one-num[i])>rounds)
					{
						num[i+1]-=(one-num[i]);
						num[i]=num[i]+rounds;
						rounds+=(one-num[i]);
						num[i]=one;
					}
					else if((one-num[i])<=rounds)
					{
						//num[i]=num[i]-rounds;
						num[i+1]-=(one-num[i]);
						//rounds+=(num[i]-one);
						num[i]=one;
					}	
				}
			}
		}
		printf("%d\n",rounds);

		}
		scanf("%d",&n);
	}
return 0;
}
