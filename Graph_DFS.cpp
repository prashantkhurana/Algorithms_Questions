#include<iostream>
#include <list>
#include<vector>
using namespace std;
 
int v;
vector<int>  *g;

void constructGraph()
{
	g=new vector<int>[v];
}

void addEdge(int v, int w)
{
    g[v].push_back(w);
}
 
void DFSUtil(int n, bool* &visited)
{
    visited[n] = true;
    cout << n << " ";

    for(vector<int>::iterator i = g[n].begin(); i!=g[n].end(); i++)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 
void DFS(int n)
{
    bool *visited=new bool[v];
    for(int i = 0; i < v; i++)
        visited[i] = false;
 
    DFSUtil(n, visited);
}
 
int main()
{
    
    v=4;
    constructGraph();
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    DFS(2);
    return 0;
}
