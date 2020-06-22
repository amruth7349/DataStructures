#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define db   double
#define sll  set<ll>
#define str  string
#define rev  reverse
#define mp   make_pair
#define pb   push_back
#define acc  accumulate
#define vll  vector<ll>
#define eb   emplace_back
#define pll  pair<ll,ll>
#define vpll vector<pair<ll,ll> >
#define dq   deque<ll>
#define puf  push_front
#define pub  push_back
#define pof  pop_front
#define pob  pop_back
ll tree[400009];
ll a[100009];
ll lazy[400009];
void initialize()
{
    for(ll i=0;i<400009;i++)
    {
        tree[i]=1;
        lazy[i]=0;
    }
}
void build(ll i,ll start,ll end)
{
    if(start==end)
    {
        tree[i]=a[start];
        return;
    }
    ll mid = (start+end)/2;
    build(i*2,start,mid);
    build(i*2+1,mid+1,end);
    tree[i]=tree[i*2]+tree[i*2+1];
}

void update(ll i,ll start,ll end,ll l,ll r)
{
    if(lazy[i]%2!=0)
    {
        tree[i]=(end-start+1)-tree[i];
        if(start!=end)
        {
            lazy[i*2]+=1;
            lazy[i*2+1]+=1;
        }
        lazy[i]=0;
    }
    if(start>end || start>r || end<l )
        return;
    if(start>=l && end<=r)
    {
        tree[i]=(end-start+1)-tree[i];
        if(start!=end)
        {
            lazy[i*2]+=1;
            lazy[i*2+1]+=1;
        }
    
        return;
    }
    ll mid =(start+end)/2;
    update(i*2,start,mid,l,r);
    update(i*2+1,mid+1,end,l,r);
    tree[i]=tree[2*i]+tree[2*i+1];

}

ll query(ll i,ll start,ll end,ll l,ll r)
{
    if(start>end || start>r || end<l)
        return 0;
    if(lazy[i]%2!=0)
    {
        tree[i]=(end-start+1)-tree[i];
        if(start!=end)
        {
            lazy[2*i]+=1;
            lazy[2*i+1]+=1;
        }
        lazy[i]=0;
    }
    if(start>=l && end<=r)
        return tree[i];
    ll mid=(start+end)/2;
    ll p1=query(i*2,start,mid,l,r);
    ll p2 = query(i*2+1,mid+1,end,l,r);
    return (p1+p2);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,i,d,e,f;
    cin >> n >> q;
    initialize();
    for(i=0;i<n;i++)
    {
        a[i]=1;
    }
    build(1,0,n-1);
    
    for(i=0;i<q;i++)
    {
        cin >> d >> e >> f;
        if(d)
        {
            cout << (f-e+1)-query(1,0,n-1,e,f) << endl;
        }
        else
        {
            update(1,0,n-1,e,f);
        }
        
    }



     return 0;
}
