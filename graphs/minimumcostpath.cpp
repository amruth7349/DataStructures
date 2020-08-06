#include <bits/stdc++.h>
using namespace std;

bool visited[10000];
vector<pair<int,int>> adj[10000];
int dist[10000];

void initialize()
{
    for(int i=0;i<10000;i++)
    {
        adj[i].clear();
        visited[i]=false;
        dist[i]=10000000;
    }
}
void djikstra(int x)
{
    multiset<pair<int,int> > s;
    s.insert({0,0});
    dist[x]=0;
    while(!s.empty())
    {
        pair<int,int> p=*s.begin();
        s.erase(*s.begin());
        int x=p.second;int wei=p.first;
        if(visited[x])
            continue;
        visited[x]=true;
        //cout << x << " " << dist[x] << endl;
        for(int i=0;i<adj[x].size();i++)
        {
            int e=adj[x][i].first;
            int w=adj[x][i].second;
            if(dist[x]+w<dist[e])
            {
                dist[e]=dist[x]+w;
                s.insert({dist[e],e});
            }
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        initialize();
        int n,m;
        cin >> n;
        m=n;
        int a[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cin >> a[i][j];
        }
        int x,y,p,q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i+1<n)
                    adj[i*m+j].push_back({(i+1)*m+j,a[i+1][j]});
                if(j+1<m)
                    adj[i*m+j].push_back({i*m+j+1,a[i][j+1]});
                if(i-1>=0 )
                    adj[i*m+j].push_back({(i-1)*m+j,a[i-1][j]});
                if(j-1>=0)
                    adj[i*m+j].push_back({i*m+j-1,a[i][j-1]});
            }
        }
        djikstra(0);
        /*for(int i=0;i<n*m;i++)
        {
            cout << i << "-->";
            for(int j=0;j<adj[i].size();j++)
            {
                cout << adj[i][j].first << " ";
            }
            cout << endl;
        }*/
        cout << dist[n*m-1]+a[0][0] << endl;
    }
}