#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	char s[1003];
	
	while(scanf("%s",s)!=EOF)
	{
		int oddcaps=0,oddsmall=0,evencaps=0,evensmall=0,odd=0,even=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(i%2==0)
			{
				if(s[i]<'a')
				oddcaps++;
				else
				oddsmall++;
			}
			else
			{
				if(s[i]<'a')
				evencaps++;
				else
				evensmall++;
			}
		}
		if(strlen(s)%2==1)
		{
			odd=strlen(s)/2+1;
			even=strlen(s)/2;
		}
		else
		{
			odd=strlen(s)/2;
			even=strlen(s)/2;
		}
		int ans1,ans2;
		ans1=oddsmall+evencaps;
		ans2=oddcaps+evensmall;
		printf("%d\n",min(ans1,ans2));
	}
	return 0;
}
