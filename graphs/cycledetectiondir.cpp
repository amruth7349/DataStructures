#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/


bool dfs(vector<int> adj[],int s,int visited[])
{
    visited[s]=1;
    //cout << s << endl;
    for(int i=0;i<adj[s].size();i++){
        int p=visited[adj[s][i]];
        if(p==1)
            return(true);
        if(p==0 && dfs(adj,adj[s][i],visited))
            return(true);
    }
    visited[s]=2;
    return(false);
}
bool isCyclic(int v, vector<int> adj[])
{
    int visited[v];
    memset(visited,0,sizeof(visited));
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
            if(dfs(adj,i,visited)==true)
                return(true);
    }
    return(false);
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends