#include <iostream>
#include<stdio.h>
using namespace std;

int d[210][210];

int main()
{
	int t, n,k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &d[i][j]);
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				for (k = 0; k < n; k++)
					if (k != i && k != j && d[i][k] + d[k][j] == d[i][j]) break;
				if (k == n)
					printf("%d %d\n", i+1, j+1);
			}
		}
		printf("\n");
	}
}
