#include<iostream>
#include <list>
#include<vector>
using namespace std;
 
int v,m=0;
vector<int>  *g;

void constructGraph()
{
	g=new vector<int>[v];
}

void addEdge(int v, int w)
{
    g[v].push_back(w);
}
 
void DFSUtil(int n, bool* &visited, bool* &marked)
{
    visited[n] = true;
    //cout << n << " ";

    for(vector<int>::iterator i = g[n].begin(); i!=g[n].end(); i++)
        if(!visited[*i]){
            DFSUtil(*i, visited,marked);
            if(marked[*i]==false && marked[n]==false){
            marked[n]=true;
            m++;
        }
        
	}
}
void DFS()
{
    bool *visited=new bool[v];
    bool *marked=new bool[v];
    for(int i = 1; i < v; i++){
        visited[i] = false;
        marked[i]=false;
    }
 	DFSUtil(1,visited,marked);
}
 
int main()
{
    

    cin>>v;
    v++;
    constructGraph();
    int x,y;
    for(int i=1;i<v-1;i++)
    {
    	cin>>x;
    	cin>>y;
    	addEdge(x,y);
    	addEdge(y,x);
    }
    //cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    DFS();
    if(v==2)
    m=1;
    cout<<m;
    return 0;
}
