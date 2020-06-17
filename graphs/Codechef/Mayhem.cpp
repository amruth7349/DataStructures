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
vll adj[1000001];
bool vis[1000001];
ll value[1000001],ans=0,cnt=0,strength=9000000000;

void initialize()
{
    for(ll i=0;i<1000001;i++)
        vis[i]=false;
}
void dfs(ll s)
{
    vis[s]=true;
    cnt++;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(vis[adj[s][i]]==false)
            dfs(adj[s][i]);
    }
}
void solve()
{
    ll n,m,i,j;
    cin >> n >> m;
    ll a[n][m];
    initialize();
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            cin >> a[i][j];
            value[i*m+j]=a[i][j];
        }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i<n-1)
            {
                if(a[i][j]==a[i+1][j])
                {
                    adj[i*m+j].pb((i+1)*m+j);
                    adj[(i+1)*m+j].pb(i*m+j);
                }
            }
            if(j<m-1)
            {
                if(a[i][j]==a[i][j+1])
                {
                    adj[i*m+j].pb(i*m+j+1);
                    adj[i*m+j+1].pb(i*m+j);
                }
            }
        }
    }
    for(i=0;i<n*m;i++)
    {
        if(vis[i]==false)
        {
            cnt=0;
            dfs(i);
            if(cnt==ans)
            {
                if(value[i]<strength)
                    strength=value[i];
            }
            else if(cnt>ans)
            {
                ans=cnt;
                strength=value[i];
            }
            
        }
    }
    cout << strength << " " << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    while(t--)
        solve();
    return 0;
}
