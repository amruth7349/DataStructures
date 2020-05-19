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

bool visited[100000];
vll adj[100000];

void initialize()
{
    for(ll i=0;i<100000;i++)
    {
        visited[i]=false;
        adj[i].clear();
    }
}

void dfs(ll s)
{
    visited[s]=true;
    cout << s << endl;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            dfs(adj[s][i]);
        }
    }
}
void solve()
{
    ll nodes,edges,i,p,q;
    cin >> nodes >> edges;
    for(i=0;i<edges;i++)
    {
        cin >> p >> q;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    for(i=1;i<=nodes;i++)
    {
        if(visited[i]==false)
            dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();

    return 0;
}