#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pb push_back

bool visited[100001];
vll adj[100001];

void initialize()
{
    for(ll i=0;i<100001;i++)
    {
        visited[i]=false;
        adj[i].clear();
    }
}

void bfs(ll s)
{
    visited[s]=true;
    list<ll> q;
    q.pb(s);
    ll i;
    while(!q.empty())
    {
        s=q.front();
        q.pop_front();
        cout << s << endl;
        for(i=0;i!=adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]]=true;
                q.pb(adj[s][i]);
            }
        }
       
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll nodes,edges,p,q;
    cin >> nodes >> edges;
    for(ll i=0;i<edges;i++)
    {
        cin >> p >> q;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    for(ll i=0;i<nodes;i++)
    {
        if(visited[i]==false)
            bfs(i);
    }

     return 0;
}