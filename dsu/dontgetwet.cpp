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

ll a[1000001];
ll size[1000001];

void initialize(ll n)
{
    for(ll i=0;i<=n;i++)
    {
        a[i]=i;
        size[i]=1;
    }
}

ll root(ll i)
{
    while(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return(i);
}

void weightedunion(ll p,ll q)
{
    ll rootp=root(p);
    ll rootq=root(q);
    if(size[rootp]<size[rootq])
    {
        a[rootp]=a[rootq];
        size[rootq]+=size[rootp];
    }
    else
    {
        a[rootq]=a[rootp];
        size[rootp]+=size[rootq];
    }
}

bool find(ll p,ll q)
{
    if(root(p)==root(q))
        return(true);
    return(false);
}

void solve()
{
    ll nodes,edges,i,j,p,q,quries;
    cin >> nodes >> edges;
    initialize(nodes);
    for(i=0;i<edges;i++)
    {
        cin >> p >> q;
        weightedunion(p,q);
    }
    cin >> quries;
    for(i=0;i<quries;i++)
    {
        cin >> p >> q;
        if(find(p,q))
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    
}