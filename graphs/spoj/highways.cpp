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
#define SIZE 100005
vector<pair<ll,ll> > v[SIZE];
ll dist[SIZE];
bool vis[SIZE];

void initialize()
{
    for(ll i=0;i<SIZE;i++)
    {
        dist[i]=100000005;
        vis[i]=false;
    }
}
void dijkstra(ll start)
{
    memset(vis,false,SIZE);
    dist[start]=0;
    multiset< pair < ll, ll > > s;
    s.insert({0,start});
    while(!s.empty())
    {
        pair<ll,ll> p = *s.begin();
        s.erase(s.begin());
        ll x=p.second;ll wei=p.first;
        if(vis[x]) 
            continue;
        vis[x]=true;
        for(ll i=0;i<v[x].size();i++)
        {
            ll e=v[x][i].first;
            ll w=v[x][i].second;
            if(dist[x]+w<dist[e])
            {
                dist[e]=dist[x]+w;
                s.insert({dist[e],e});
            }
        }
    }
}

void solve()
{
    ll nodes,edges,start,end,p,q,w,i;
    cin >> nodes >> edges >> start >> end;
    initialize();
    for(i=0;i<edges;i++)
    {
        cin >> p >> q >> w;
        v[p].pb(mp(q,w));
        v[q].pb(mp(p,w));
    }
    dist[start]=0;
    dijkstra(start);
    if(dist[end]==100000005)
        cout << "NONE" << endl;
    else 
        cout << dist[end] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}