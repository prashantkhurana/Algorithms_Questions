#include<iostream>
#include<climits>

using namespace std;

bool numbers[35000];
int lucky[5000];

int main()
{
	int x=1;
	
	int count;
	
	for(int i=2;i<35000;i++)
	{
		if(numbers[i]==false)
		{
			lucky[x++]=i;
			count=0;
			for(int j=i+1;j<35000;j++)
			{
				if(numbers[j]==false)
				{
					count++;
				}
				if(count==i)
				{
					numbers[j]=true;
					count=0;
				}
			}
		}
	}
	int n;
	do
	{
		scanf("%d",&n);
		if(n!=0)
		printf("%d\n",lucky[n]);
	}while(n!=0);
	
	return 0;
}
