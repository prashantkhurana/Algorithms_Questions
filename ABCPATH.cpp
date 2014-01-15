#include <string.h>
#include<stdio.h>
#include <algorithm>

using namespace std;

int n, m;
char a[55][55];
int  d[55][55];

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

bool exists (int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

int solve (int x, int y) {
  if(d[x][y] != -1)
    return d[x][y];
  d[x][y] = 1;
  for(int k = 0; k < 8; ++k) {
    int x1 = x + dx[k];
    int y1 = y + dy[k];
    if(exists(x1, y1)) {
      if(a[x1][y1] == a[x][y] + 1) {
        d[x][y] = max(d[x][y], 1 + solve(x1, y1));
      }
    }
  }
  return d[x][y];
}

int main () {

	int z=1;
  while(scanf("%d%d", &n, &m)) {
    if(n == 0 && m == 0)
      break;
    for(int i = 0; i < n; i++) {
      scanf("%s", a[i]);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        d[i][j] = -1;
      }
    }
    int ans=0;
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(a[i][j] == 'A' && d[i][j] == -1) {
          ans = max(ans, solve(i, j));
        }
      }
    }
    //if(ans==0)
    //printf("Case %d: %d\n", z, ans);
    //else
    printf("Case %d: %d\n", z, ans);
    z++;
  }
  return 0;
}
