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
ll marks[100000];

void initialize()
{
    for(ll i=0;i<=1000000;i++)
    {
        a[i]=i;
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

void wunion(ll p ,ll q)
{
    ll rp=root(p);
    ll rq=root(q);
    if(rp==rq)
        cout << "Invalid query!" << endl;
    if(marks[rp]>marks[rq])
        a[rq]=a[rp];
    else if(marks[rq]>marks[rp])
        a[rp]=a[rq];
}

void solve()
{
    initialize();
    ll n,i,j,p,q,queries;
    cin >> n;
    for(i=1;i<=n;i++)
        cin >> marks[i];
    cin >> queries;
    for(i=0;i<queries;i++)
    {
        cin >> j;
        if(j)
        {
            cin >> p;
            cout << root(p) << endl;
        }
        else
        {
            cin >> p >> q;
            wunion(p,q);
        }
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