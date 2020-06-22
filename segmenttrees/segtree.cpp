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
ll tree[100001];
ll a[100001];
ll lazy[100001];
void build(ll node,ll start,ll end)
{
    if(start==end)
    {
        tree[node]=a[start];
    }
    else
    {
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
void update(ll node,ll start,ll end,ll index,ll value)
{
    if(start==end)
    {
        tree[node]=value;
        a[index]=value;
    }
    else
    {
        ll mid=(start+end)/2;
        if(start<=index && index<=mid)
            update(node*2,start,mid,index,value);
        else
            update(node*2+1,mid+1,end,index,value);
        tree[node]=tree[2*node]+tree[2*node+1];
        
    }  
}
ll query(ll node,ll start,ll end,ll left,ll right)
{
    if(right<start || end<left)
        return 0;
    if(left<=start && end<=right)
        return tree[node];
    ll mid = (start+end)/2;
    ll p1 = query(node*2,start,end,left,right);
    ll p2 = query(node*2+1,mid+1,end,left,right);
    return(p1+p2);
}

void updaterange(ll node,ll start,ll end,ll left,ll right,ll value)
{
    if(right<start || end<left)
        return ;
    if(start==end)
    {
        tree[node]+=value;
        return;
    }
    ll mid = (start+end/2);
    updaterange(2*node,start,mid,left,right,value);
    updaterange(2*node+1,mid+1,end,left,right,value);
    tree[node]=tree[2*node]+tree[2*node+1];
}
void updateRange(ll node,ll start,ll end,ll left,ll right,ll value)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>end || start>right || end<left)
        return ;
    if(left<=start && end<=right)
    {
        tree[node]+=(end-start+1)*value;
        if(start!=end)
        {
            lazy[2*node]+=value;
            lazy[2*node+1]+=value;
        }
        return;
    }
    ll mid=(start+end)/2;
    updateRange(2*node,start,mid,left,right,value);
    updateRange(2*node+1,mid+1,end,left,right,value);
    tree[node]=tree[2*node]+tree[2*node+1];

}
ll queryRange(ll node,ll start,ll end,ll left,ll right)
{
    if(start>end || start>right || end<left)
        return 0;
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)
        {
            lazy[node*2]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=left && end<=right)
        return tree[node];
    ll mid = (start+end)/2;
    ll p1 = queryRange(node*2,start,mid,left,right);
    ll p2 = queryRange(node*2+1,mid+1,end,left,right);
    return (p1+p2);
}
void print()
{
   for(ll i=1;i<10;i++)
   {
       cout << (tree[i]) << " ";
   }
   cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,i,m,left,p,right,value;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        lazy[i]=0;
    }
    build(1,0,n-1);
    print();
    cin >> m;
    for (i=0;i<m;i++)
    {
        cin >> p >> left >> right;
        if(p==1)
        {
            cout << queryRange(1,0,n-1,left,right);
        }
        else
        {
            cin >> value;
            updateRange(1,0,n-1,left,right,value);
        }
        
    }
    
    return 0;
}
