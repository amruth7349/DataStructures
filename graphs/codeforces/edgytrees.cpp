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
ll c;
void intialize()
{
    for(ll i=0;i<100001;i++)
        visited[i]=false;
        
}

void dfs(ll s)
{
    visited[s]=true;
    c++;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            dfs(adj[s][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    intialize();
    ll n,k,i,p,q,r,ans=0;
    cin >> n >> k;
    for(i=0;i<n-1;i++)
    {
        cin >> p >> q >> r;
        if(!r)
        {
            adj[p].pb(q);
            adj[q].pb(p);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            c=0;
            dfs(i);
            ll p=1;
            //cout << c << endl;
            for(ll j=0;j<k;j++)
            {
                p=((p%1000000007)*(c%1000000007))%(1000000007);
            }
            ans=(ans%1000000007+p%1000000007)%1000000007;
        }
    }
     q=1;
     //cout << q << " " << ans <<endl;
    for(i=0;i<k;i++)
    {
        q=((q%1000000007)*(n%1000000007))%1000000007;
    }
    cout << (q-ans+1000000007)%1000000007 << endl;
    
    
}
