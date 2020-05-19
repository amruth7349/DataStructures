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

ll id[200005],nodes,edges;
pair<ll,pll> p[200005];

void initialize()
{
    for(ll i=0;i<200005;i++)
        id[i]=i;
}

ll root(ll x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return(x);
}

void union1(ll x,ll y)
{
    ll p=root(x);
    ll q=root(y);
    id[p]=id[q];
}

ll kruskal(pair<ll,pll> p[])
{
    ll x,y,cost,mincost=0,i;
    for(i=0;i<edges;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(root(x)!=root(y))
        {
            mincost+=cost;
            union1(x,y);
        }
    }
    return(mincost);
}
void solve()
{
    ll x,y,weight,cost,mincost,i;
    initialize();
    cin >> nodes >> edges;
    for(i=0;i<edges;i++)
    {
        cin >> x >> y >> weight;
        p[i]=mp(weight,mp(x,y));
    }
    sort(p,p+edges);
    mincost=kruskal(p);
    cout << mincost << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();
    return 0;
}