#include <iostream>
using namespace std;

double d[102][102];

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2 && n > 0)
	 {
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= n; j++)
			if(i==j)
				d[i][i]=1;
			else
				d[i][j] = 0;
		}	

		int a,b,p;
		for (int i = 0; i < m; i++) 
		{
			scanf("%d %d %d", &a, &b, &p);
			d[a][b] = d[b][a]= p/100.0;
		}

		for (int k = 1; k < n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (d[i][k] * d[k][j] > d[i][j])
						d[i][j] = d[i][k] * d[k][j];
		
		printf("%.6f percent\n",d[1][n]*100);				
	}
	return 0;
}

