#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool ans;
void dfs(vector<int> adj[],int s,bool visited[],int parent)
{
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
            dfs(adj,adj[s][i],visited,s);
        else if(adj[s][i]==parent)
            continue;
        else 
            ans=true;
    }
}

bool isCyclic(vector<int> g[], int V)
{
    ans=false;
   bool visited[V];
   memset(visited,false,sizeof(visited));
   for(int i=0;i<V;i++)
   {
        if(!visited[i])
        {
            dfs(g,i,visited,-1);
        }
   }
   return(ans);
   
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends