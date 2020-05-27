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

vll adj[2*100000];
bool visited[2*100000];
ll flag;

void initialize()
{
    for(ll i=0;i<2*100000;i++)
    {
        visited[i]=false;
    }
}

void dfs(ll s)
{
    visited[s]=true;
    //cout << s << endl;
    if(adj[s].size()!=2)
        flag=0;
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
    ll n,m,i,p,q,count=0;
    cin >> n >> m;
    initialize();
    for(i=0;i<m;i++)
    {
        cin >> p >> q;
        adj[p-1].pb(q-1);
        adj[q-1].pb(p-1);
    }
    for(i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            flag=1;
            dfs(i);
            //cout << flag << endl;
            if(flag)
                count++;
        }
    }
    cout << count;
    return 0;
}
