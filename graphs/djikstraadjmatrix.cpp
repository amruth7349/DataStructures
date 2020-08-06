#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
int dist[100];
bool visited[100];
void initialize()
{
    for(int i=0;i<100;i++)
    {
        dist[i]=10000000;
        visited[i]=false;
    }
}
vector <int> dijkstra(vector<vector<int>> g, int src, int v)
{
    initialize();
    dist[src]=0;
    multiset<pair<int,int> >s;
    s.insert({0,src});
    while(!s.empty())
    {
        pair<int,int> p = *s.begin();
        s.erase(*s.begin());
        int x=p.second; int wei=p.first;
        if(visited[x])
            continue;
        visited[x]=true;
        for(int i=0;i<v;i++)
        {
            if(dist[x]+g[x][i]<dist[i] && g[x][i]!=0)
            {
                dist[i]=dist[x]+g[x][i];
                s.insert({dist[i],i});
            }
        }
    }
    vector<int>ans;
    for(int i=0;i<v;i++)
    {
        ans.push_back(dist[i]);
    }
    return(ans);
}