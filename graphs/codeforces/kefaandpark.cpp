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

vll adj[200005];
bool visited[200005];
ll iscat[200005],ans=0,m;

void initialize()
{
    for(ll i=0;i<200005;i++)
    {
        visited[i]=false;
        adj[i].clear();
    }
}

void dfs(ll s,ll c)
{
    visited[s]=true;
    if(iscat[s])
        c++;
    if(adj[s].size()==1 and c<=m and s!=1)
    {
        ans++;
        //cout << s << " " << c << endl;
    }
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            if(c>m)
                dfs(adj[s][i],c);
            else if(iscat[adj[s][i]])
                dfs(adj[s][i],c);
            else
                dfs(adj[s][i],0);
        }
    }
}

void solve()
{
    ll n,i,c,p,q;
    cin >> n >> m;
    for(i=1;i<=n;i++)
        cin >> iscat[i];
    for(i=0;i<n-1;i++)
    {
        cin >> p >> q;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    //cout << endl;
    dfs(1,0);
    cout << ans << endl;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}