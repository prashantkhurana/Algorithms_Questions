#include <stdio.h>
#include<math.h>


using namespace std ;

int main( )
{
  	int n ,i,m, sum ,p,x;
  	

	while(1)
	{
		scanf("%d",&n);
		if(!n)
		break;
		sum=0;
		m=n;
		i=-1;
		x=ceil((double)n/2);
		x=n-x;
		for(i=0;i<n;i++)
		{
			scanf("%d",&p);
			if(i>=x)
			sum+=p;
		}
		
		printf("%d\n",sum) ;
	}

	return 0 ;
}
