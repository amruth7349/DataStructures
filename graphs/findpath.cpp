#include <bits/stdc++.h>
using namespace std;

bool visited[400];
vector<int> adj[400];
int dist[400];

void initialize()
{
    for(int i=0;i<400;i++)
    {
        adj[i].clear();
        visited[i]=false;
        dist[i]=100000;
    }
}
void bfs(int s)
{
    dist[s]=0;
    visited[s]=true;
    list<int> q;
    q.push_back(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop_front();
        //cout << s << endl;
        for(int i=0;i<adj[s].size();i++)
        {
            if(visited[adj[s][i]])
                continue;
            visited[adj[s][i]]=true;
            q.push_back(adj[s][i]);
            dist[adj[s][i]]=dist[s]+1;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--)
    {
        initialize();
        int n,m;
        cin >> n >> m;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                    continue;
                if(i+1<n && a[i+1][j])
                    adj[i*m+j].push_back((i+1)*m+j);
                if(j+1<m && a[i][j+1])
                    adj[i*m+j].push_back(i*m+j+1);
                if(i-1>=0 and a[i-1][j])
                    adj[i*m+j].push_back((i-1)*m+j);
                if(j-1>=0 && a[i][j-1])
                    adj[i*m+j].push_back(i*m+j-1);
            }
        }
        int x,y;
        cin >> x >> y;
        //x--;y--;
        int p=x*m+y;
       // cout << x << endl;
        bfs(0);
        if(dist[p]!=100000 and a[x][y])
            cout << dist[p] << endl;
        else 
            cout << -1 << endl;
       
    }
	return 0;
}