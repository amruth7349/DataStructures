#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define sll set<ll>
#define str string
#define rev reverse
#define mp make_pair
#define pb push_back
#define acc accumulate
#define vll vector<ll>
#define eb emplace_back
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll> >
#define dq deque<ll>
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mll map<ll,ll>
 
vll adj[1000001];
bool visited[1000001];
ll dist[1000001];
void initialize()
{
    for(ll i=0;i<=1000000;i++)
    {
        visited[i]=false;
        dist[i]=0;
 
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
        for(i=0;i!=adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]]=true;
                q.pb(adj[s][i]);
                dist[adj[s][i]]=dist[s]+1;
            }
        }
       
    }
}
void solve()
{
    ll n,start,end,u,d,i,j;
    cin >> n >> start >> end >> u >> d;
    for(ll i=1;i<=n;i++)
    {
        if(i+u<=n)
        {
            adj[i].pb(i+u);
        }
        if(i-d>=1)
        {
            adj[i].pb(i-d);
        }
    }
    bfs(start);
    if(start==end)
        cout << 0 << endl;
    else if(dist[end])
        cout << dist[end] << endl;
    else
        cout << "use the stairs" << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();
 
    return 0;
} 