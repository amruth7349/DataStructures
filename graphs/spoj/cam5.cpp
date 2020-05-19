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
 
ll visited[100005];
vll adj[100005];
 
void initialize()
{
    for(ll i=0;i<100005;i++)
    {
        visited[i]=false;
        adj[i].clear();
    }
}
void dfs(ll s)
{
    visited[s]=true;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
            dfs(adj[s][i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,e,p,q,c=0;
        initialize();
        cin >> n >> e;
        for(ll i=0;i<e;i++)
        {
            cin >> p >> q;
            adj[p].pb(q);
            adj[q].pb(p);
        }
        for(ll i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i);
                c++;
            }
        }
        cout << c << endl;
 
    }
 
     return 0;
}
 