#include<iostream>
#include <list>
#include<vector>
#include<cctype>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
 
int v,s,f;
vector<int>  *g;

void constructGraph()
{
	g=new vector<int>[v];
}

void addEdge(int v, int w)
{
    g[v].push_back(w);
}
 
int solveProblem(int n,int &nsf,bool* &visited,int &ts,int &tf)
{
	visited[n]=true;
	if((g[n].begin()==g[n].end()))
	{
		nsf=0;
		ts++;
		return s;
	}
	int sums=0,sumf=0,temp=nsf;
	if(temp==-1)
	{
		nsf=0;
		int ts1=0,ts2=0,tf1=0,tf2=0;
		int x=solveProblem(n,nsf,visited,ts1,tf1);
		nsf=1;
		int y=solveProblem(n,nsf,visited,ts2,tf2);
		if(x<y)
		{
			nsf=0;
			ts=ts1;
			tf=tf1;
		}
		else
		{
			nsf=1;
			ts=ts2;
			tf=tf2;
		}
		return min(x,y);
	}
	
	for(vector<int>::iterator i=g[n].begin();i!=g[n].end();i++)
	{
		nsf=-1;
		sums=sums+solveProblem(*i,nsf,visited,ts,tf);
		if(temp==1 && nsf==0){
				sums--;
				ts--;
			}
	}
	if(temp==0)
	ts++;
	else
	tf++;
	if(temp==0)
	return s+sums;
	else
	return f+sums;
}
int main()
{
    
    int i,k=1;
    map<string,int> m;
    char z[110000];
    char *w;
    	cin.getline(z,110000);
    	v=100000;
    	constructGraph();
    do
    {
    	
    
    	if(strcmp(z,"0 0"))
    	{
    		s=atoi(strtok(z," "));
    		f=atoi(strtok(NULL," "));
    		i=0;
    		do{
    		cin.getline(z,110000);
    		if(!isdigit(z[0]))
    		{
    			string q=strtok(z," ");
    			
    			if(m.find(q)==m.end())
    			{
    				m.insert(std::pair<string,int>(q,i));
    				i++;
    			}
    			do
    			{
    				w=strtok(NULL," ");
    				if(w){
    				if(m.find(w)==m.end())
    				{
    				m.insert(std::pair<string,int>(w,i));
    				i++;
    				addEdge(m.find(q)->second,i-1);
    				}
    				else
    				{
    				addEdge(m.find(q)->second,m.find(w)->second);
    				}
    			}
    			}while(w);
    		}
    	}while(!isdigit(z[0]));
    	int nsf=-1,l=0,ts=0,tf=0;
    	bool *visited=new bool[i];
    	for(int j=0;j<i;j++)
    	visited[j]=false;
    	for(int j=0;j<i;j++)
    	{
    		nsf=-1;
    		if(visited[j]==false)
    		l+=solveProblem(j,nsf,visited,ts,tf);
    	}
    	cout<<k<<"."<<" "<<ts<<" "<<tf<<" "<<l<<endl;
    	k++;
    	delete visited;
    }
    
}while(strcmp(z,"0 0"));
return 0;
}
