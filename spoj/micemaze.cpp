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

vpll adj[200];
bool visited[200];
ll dist[200][200];

void initialize()
{
    for(ll i=0;i<200;i++)
    {
        visited[i]=false;
        for(ll j=0;j<200;j++)
        {
            if(i!=j)
                dist[i][j]=500000;
            else 
                dist[i][j]=0;
        }
    }
}

void flody(ll n)
{
    for(ll k=1;k<=n;k++)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

}

void solve()
{
    ll n,e,t,edges,a,b,ans=0,w;
    cin >> n >> e >> t >> edges;
    initialize();
    for(ll i=0;i<edges;i++)
    {
        cin >> a >> b >> w;
        ll flag=1;
        for(ll j=0;j<adj[a].size();j++)
        {
            ll k=adj[a][j].first; ll g=adj[a][j].second;
            if(k==b && a!=b)
            {
                flag=0;
                adj[a][j].second=min(w,g);
                w=adj[a][j].second;
                dist[a][b]=w;
                break;
            }
                
        }
        if(flag)
        {
            if(a!=b)
            {
                adj[a].pb(mp(b,w));
                dist[a][b]=w;
            }
        }

    }
    //dist[1][1]=0;
    flody(n);
    for(ll i=1;i<=n;i++)
    {
        //cout << dist[i][e] << endl;
        if(dist[i][e]<=t)
            ans++;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();

    return 0;
}