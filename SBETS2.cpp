#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int t;

	scanf("%d",&t);
	while(t--) 
	{
		
		string s1;
		string s2;
		int goal1;
		int goal2;
		map <string, int> m;
		for (int j = 0; j < 16; j++) {
			cin>>s1>>s2;
			scanf("%d %d",&goal1,&goal2);
			if (goal1 > goal2) {
				if(m.find(s1)==m.end())
				{
					m[s1]=1;
				}
				if(m.find(s2)!=m.end())
				{
					m[s2]=0;
				}
				else
				{
					m[s2]=0;
				}
			} else {
				if(m.find(s2)==m.end())
				{
					m[s2]=1;
				}
				if(m.find(s1)!=m.end())
				{
					m[s1]=0;
				}
				else
				{
					m[s1]=0;
				}
			}
		}
		for(std::map<string,int>::iterator it=m.begin();it!=m.end();it++)
		{
			if(it->second==1)
			cout<<it->first<<endl;
		}
	}
	return 0;
}

