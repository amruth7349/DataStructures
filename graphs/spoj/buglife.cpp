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
 
vll adj[2002];
bool visited[2002];
ll gender[2002];
ll f=0;
void initialize()
{
    f=0;
    for(ll i=0;i<2002;i++)
    {
        adj[i].clear();
        visited[i]=false;
        gender[i]=-1;
    }
}
 
void dfs(ll s)
{
    visited[s]=true;
    ll g=-1;
    if(gender[s]==-1)
    {
        g=1;
        gender[s]=0;
    }
    else
        g=gender[s]^1;
    
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            gender[adj[s][i]]=g;
            dfs(adj[s][i]);
        }
        else
        {
            if(gender[s]==gender[adj[s][i]] )
            {
                f=1;
                return;
            }
        }
        
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t,u=1;
    cin >> t;
    while(t--)
    {
        ll n,e,p,q;
        cin >> n >> e;
        initialize();
        for(ll i=0;i<e;i++)
        {
            cin >> p >> q;
            adj[p].pb(q);
            adj[q].pb(p);
 
        }
        ll c=0;
        for(ll i=1;i<n+1;i++)
        {
            if(visited[i]==false)
            {
                dfs(i);
                c++;
            }
        }
        /*for(ll i=1;i<n+1;i++)
        {
            cout << gender[i] << " ";
        }
        cout << endl;*/
        if(f==0)
        {
            cout << "Scenario #" << u++ << ":" << endl;
            cout << "No suspicious bugs found!" << endl;
 
        }
        else
        {
            cout << "Scenario #" << u++ << ":" << endl;
            cout << "Suspicious bugs found!" << endl;
        }
        
 
    }
 
     return 0;
} 