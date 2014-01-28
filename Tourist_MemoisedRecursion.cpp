#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxN = 107;
const int maxM = 107;

int n, m;
char a[maxN][maxM];
int  f[maxN][maxM][maxN];

void init () {
  scanf("%d%d", &n, &m);
  swap(m, n);
  for(int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }

  memset(f, -1, sizeof(f));
}

inline bool valid (int x, int y) {
  if(x < 0 || x >= n || y < 0 || y >= m)
    return false;

  if(a[x][y] == '#')
    return false;

  return true;
}

int go (int row1, int col1, int col2) {

  int &ref = f[row1][col1][col2];

  if(ref != -1) {
    return ref;
  }
  if(row1 == n - 1 && col1 == n - 1 && row1+col1 == n + m-2) {
    ref = 0;
    if(a[n - 1][m - 1] == '*') {
      ref += 1;
    }

    return ref;
  }

  ref = 0;
  int row2=row1+col1-col2;

  ref += (a[row1][col1] == '*');
  ref += (a[row2][col2] == '*');
  
  if(ref == 2) {
    ref -= (row1 == row2 && col1 == col2);
  }

  int mmax = 0;

      if(valid(row1, col1+1) && valid(row2, col2+1)) 
        mmax = max(mmax, go(row1, col1+1, col2+1));
        if(valid(row1, col1+1) && valid(row2+1, col2))
        mmax = max(mmax, go(row1, col1+1, col2));
        if(valid(row1+1, col1) && valid(row2+1, col2))
        mmax = max(mmax, go(row1+1, col1, col2));
		if(valid(row1+1, col1) && valid(row2, col2+1))
        mmax = max(mmax, go(row1+1, col1, col2+1));


  ref += mmax;
	f[row1][col1][col2]=ref;
	f[row1+col1-col2][col2][col1]=ref;
  return ref;
}

int main () {
  int test_case;
  scanf("%d", &test_case);

  while(test_case--) {
    init();
    printf("%d\n", go(0, 0, 0));
  }
  
  return 0;
}
