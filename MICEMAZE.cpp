#include <iostream>
#include<climits>
using namespace std;

double d[102][102];

int main()
{
	int n, m,e,t;
	scanf("%d\n%d\n%d\n%d", &n,&e,&t,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			d[i][j]=INT_MAX;
			else
			d[i][j]=0;
		}
	}
	 {
		int a,b,p;
		for (int i = 0; i < m; i++) 
		{
			scanf("%d %d %d", &a, &b, &p);
			d[a-1][b-1] = p;
		}

		for (int k =0 ; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (d[i][k] +d[k][j] <d[i][j] &&(d[i][k] +d[k][j])>0 )
						d[i][j] = d[i][k] + d[k][j];
		
		int x=0;
		for(int i=0;i<n;i++)
		{
			if(d[i][e-1]<=t)
			x++;
		}
		printf("%d\n",x);				
	}
	return 0;
}

