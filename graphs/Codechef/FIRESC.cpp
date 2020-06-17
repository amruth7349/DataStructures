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

vll adj[100002];
bool visited[100002];

ll initialize()
{
    for(ll i=0;i<100002;i++)
    {
        visited[i]=false;
        adj[i].clear();
    }
}

ll dfs(ll s)
{
    visited[s]=true;
    ll k=1;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
        {
            k+=dfs(adj[s][i]);
        }

    }
    return k;

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n,m,i,p,q,c=0,pro=1;
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
                ll k=dfs(i);
                pro*=k;
                pro=pro%(1000000007);
                c++;
            }
        }
        cout << c << " " << pro << endl;
        




    }

    return 0;
}
