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
 
vpll adj[600];
bool visited[600];
ll dist[600];
 
void dijkstra(ll n)
{
    
    for(ll i=0;i<600;i++)
    {
        visited[i]=false;
        dist[i]=500000;
    }    
    dist[n]=0;  
    multiset<pll> m;
    m.insert(mp(0,n));
    while(!m.empty())
    {
        pll p=*m.begin();
        m.erase(m.begin());
        ll node=p.second;ll dis=p.first;
        //cout << node   << adj[node].size() << endl;
        if(visited[node])
            continue;
        visited[node]=true;
        for(ll i=0;i<adj[node].size();i++)
        {
            ll x=adj[node][i].first;
            ll y=adj[node][i].second;
            if(dist[x]>dist[node]+y)
            {
                dist[x]=dist[node]+y;
                m.insert(mp(dist[x],x));
            }
            
        }
    }
    
}
 
void solve()
{
    ll edges,a,b,w,n,q,p;
    cin >> edges;
    for(ll i=0;i<edges;i++)
    {
        cin >> a >> b >> w;
        ll flag=1;
        for(ll j=0;j<adj[a].size();j++)
        {
            ll k=adj[a][j].first; ll g=adj[a][j].second;
            if(k==b)
            {
                flag=0;
                adj[a][j].second=min(w,g);
                w=adj[a][j].second;
                break;
            }
                
        }
        if(flag)
        {
            if(a!=b)
            {
                adj[a].pb(mp(b,w));
                adj[b].pb(mp(a,w));
            }
        }
        else 
        {
            for(ll j=0;j<adj[b].size();j++)
            {
                ll k=adj[b][j].first;
                if(k==a)
                {
                    adj[b][j].second=w;
                    break;
                }
            }
        }
        
    }
    cin >> n >> q;
    dijkstra(n);
    for(auto i=0;i<q;i++)
    {
        cin >> p;
        if(dist[p]!=500000)
            cout << dist[p] << endl;
        else 
            cout << "NO PATH" << endl;
    }
    /*for(ll i=0;i<12;i++)
    {
        cout << i << "->";
        for(ll j=0;j<adj[i].size();j++)
            cout << adj[i][j].first << " ";
        cout << endl;
    }*/
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();
 
    return 0;
} 
