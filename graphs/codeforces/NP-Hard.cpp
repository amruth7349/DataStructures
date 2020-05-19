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

vll adj[100001];
bool visited[100001];
ll check[100001],f=0;

void initialize()
{
    for(ll i=0;i<100001;i++)
    {
        visited[i]=false;
        check[i]=-1;
    }
}

void dfs(ll s)
{
    visited[s]=true;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            check[adj[s][i]]=check[s]^1;
            dfs(adj[s][i]);
        }
        else if(check[s]==check[adj[s][i]])
            f=1;
    }
}
void solve()
{
    initialize();
    ll n,m,i,p,q,c=0,d=0;
    cin >> n >> m;
    for(i=0;i<m;i++)
    {
        cin >> p >> q;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            check[i]=1;
            dfs(i);
        }
    }
    if(f)
        cout << -1 << endl;
    else
    {
        for(i=1;i<=n;i++)
        {
            if(check[i])
                c++;
            else
                d++;
        }
        cout << c << endl;
        for(i=1;i<=n;i++)
        {
            if(check[i])
                cout << i << " ";
        }
        cout << endl << d << endl;
        for(i=1;i<=n;i++)
        {
            if(!check[i])
                cout << i << " ";
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}