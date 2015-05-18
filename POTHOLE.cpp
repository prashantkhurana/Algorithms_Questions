#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include<stdio.h>
using namespace std;
 
// Number of vertices in given graph
int  V;
 
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(vector<int> g[], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    //parent[s] = -1;
 	int b=1;
 	int u2;
    // Standard BFS Loop
    while (!q.empty()&&b==1)
    {
        u2 = q.front();
        q.pop();
 		
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && g[u2][v] > 0)
            {
                q.push(v);
                parent[v] = u2;
                visited[v] = true;
                if(v==t)
 				b=0;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}
 
// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(vector<int> g[], int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    vector<int> rg[V]; // Residual graph where rGraph[i][j] indicates
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not) 
                     
    for(int i=0;i<V;i++)
    {
    	rg[i].reserve(V);
    }
                 
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rg[u][v] = g[u][v];
 
    int parent[V];  // This array is filled by BFS and to store path
 
    int max_flow = 0;  // There is no flow initially
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rg, s, t, parent))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rg[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rg[u][v] -= path_flow;
            rg[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
 
// Driver program to test above functions
int main()
{
	int t,n;
	scanf("%d\n",&t);
	while(t--)
	{
		scanf("%d\n",&V);
		vector<int> g[V];
    
    	for(int i=0;i<V;i++)
    	{
    		g[i].assign(V,0);
    		//g[i].assign(g[i].begin(),g[i].end(),0);
    	}
    
    	int x;
    		scanf("%d",&n);
    		for(int j=0;j<n;j++)
    		{
    			scanf("%d",&x);
    			g[0][x-1]=1;
    			g[x-1][0]=0;
    		}
    	for(int i=1;i<V-1;i++)
    	{
    		scanf("%d",&n);
    		for(int j=0;j<n;j++)
    		{
    			scanf("%d",&x);
    			g[i][x-1]=INT_MAX;
    			g[x-1][i]=0;
    		}
    	}
    	
    	x=V-1;
    		for(int j=0;j<V;j++)
    		{
    			//scanf("%d",&x);
    			if(g[j][x]==INT_MAX)
    			g[j][x]=1;
    			//=1;
    			//g[V-2][x-1]=-1000;
    		}
//    	for(int i=0;i<V;i++)
//    	{
//    		for(int j=0;j<V;j++)
//    		printf("%d ", g[i][j]);
//    		printf("\n");
//    	}	
//    	
    	cout << fordFulkerson(g, 0, V-1)<<endl;

	}
    // Let us create a graph shown in the above example
    
    
//    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
//                        {0, 0, 10, 12, 0, 0},
//                        {0, 4, 0, 0, 14, 0},
//                        {0, 0, 9, 0, 0, 20},
//                        {0, 0, 0, 7, 0, 4},
//                        {0, 0, 0, 0, 0, 0}
//                      };
    
 
    return 0;
}
