#include<iostream>
#include<map>
#include<string.h>
using namespace std;

char s[1000002];

int length[1000002];
int main()

{
	
	
	int n;
	std::map<char, int>::iterator it;
	map<char, int> m;
	
	int maxlength;


	while(scanf("%d",&n) && n)
	{
		
  		scanf(" %[^\n]s", s);	
  		m.clear();
		memset(length,0,sizeof(length));
		for(int i=0;s[i]!='\0';i++)
		{
			if(i==0)
			length[i]=0;
			else
			length[i]=length[i-1];
			if(m.find(s[i])==m.end())
			{
				if(m.size()<n)
				{
					m[s[i]]=1;
					length[i]=length[i]+1;
				}
				else
				{
					for(int j=i-length[i-1];j<i;j++)
					{
						m[s[j]]--;
						length[i]=length[i]-1;
						if(m[s[j]]==0)
						{
							it=m.find(s[j]);
							m.erase(it);
						
							break;
						}
					}
					m[s[i]]=1;
						length[i]=length[i]+1;
				}
			}
			else
			{
					m[s[i]]++;
					length[i]=length[i]+1;
			}
			
//			for(it=m.begin();it!=m.end();it++)
//			cout<<it->first;
//			cout<<endl;
		}
		maxlength=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(length[i]>maxlength)
			maxlength=length[i];
		}
		printf("%d\n",maxlength);
	}
	return 0;
}
