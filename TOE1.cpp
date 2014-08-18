	#include <cstdio>
	#include <vector>
	#include <cmath>
	
	using namespace std;
	
	int count(char a[][3], char t)
	{
	  int c = 0;
	  for(int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
	      if(a[i][j]==t)
	        c++;
	  return c;
	}
	bool win(char a[][3], char t)
	{
	  if(a[0][0]==t&&a[0][1]==t&&a[0][2]==t)
	    return true;
	  if(a[1][0]==t&&a[1][1]==t&&a[1][2]==t)
	    return true;
	  if(a[2][0]==t&&a[2][1]==t&&a[2][2]==t)
	    return true;
	  if(a[0][0]==t&&a[1][0]==t&&a[2][0]==t)
	    return true;
	  if(a[0][1]==t&&a[1][1]==t&&a[2][1]==t)
	    return true;
	  if(a[0][2]==t&&a[1][2]==t&&a[2][2]==t)
	    return true;
	  if(a[0][0]==t&&a[1][1]==t&&a[2][2]==t)
	    return true;
	  if(a[2][0]==t&&a[1][1]==t&&a[0][2]==t)
	    return true;
	  return false;
	}
	int main()
	{
	  int n;
	  scanf("%d",&n);
	  char a[3][3];
	  char dummy;
	  int countx,counto;
	  int i=n;
	  while(i-->0)
	  {
	    bool flag = 0;
	    for(int j=0;j<3;j++)
	      scanf("%s",a[j]);
	
	
	    countx = count(a,'X');
	    counto = count(a,'O');
	    if(countx<counto||countx-counto>1)
	    {
	      printf("no\n");
	      flag = 1;
	    }
	    if(countx==counto)
	    {
	    	if(win(a,'X'))
	    	{
	    		printf("no\n");
	      		flag = 1;
	    	}
	      	
	    }
	    if(countx>counto)
	    {
	    	if(win(a,'O'))
	    	{
	    		printf("no\n");
	      	flag = 1;
	    	}
	    }
	    if(flag==0)
	      printf("yes\n");
	  }
	  return 0;
	}
	

