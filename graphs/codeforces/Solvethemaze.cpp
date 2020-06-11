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
bool visited[3000],vis[3000],flag;
vll adj[3000];
char a[50][50], c[3000];
int cnt;

void initialize()
{
    for(ll i=0;i<3000;i++)
    {
        cnt=0;
        flag=0;
        visited[i]=false;
        vis[i]=false;
        adj[i].clear();
    }
}

void dfs(ll s)
{
    visited[s]=true;
   // cout << s << endl;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(c[adj[s][i]]=='B' && c[s]=='.')
        {
            c[s]='#';
            break;
        }
        else
        {
            if(!visited[adj[s][i]])
                dfs(adj[s][i]);
        }
    }
}
void dfs1(ll s)
{
    //cout << s << endl;
    if(c[s]=='#')
        return;
    if(c[s]=='G')
        cnt--;
    if(c[s]=='B')
    {
        flag=1;
        //cout << s << endl;
    }
    vis[s]=true;
    for(ll i=0;i<adj[s].size();i++)
    {
        if(!vis[adj[s][i]])
            dfs1(adj[s][i]);
    }
}
void solve()
{
    initialize();
    ll n,m,i,j;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> a[i][j];
            c[i*m+j]=a[i][j];
            if(a[i][j]=='G')
                cnt++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j]=='#')
                continue;
            if(i>0 && a[i-1][j]!='#')
                adj[i*m+j].pb((i-1)*m+j);
            if(i<n-1 && a[i+1][j]!='#')
                adj[i*m+j].pb((i+1)*m+j);
            if(j>0 && a[i][j-1]!='#')
                adj[i*m+j].pb(i*m+j-1);
            if(j<m-1 && a[i][j+1]!='#')
                adj[i*m+j].pb(i*m+j+1);
        }
    }
    dfs(n*m-1);
    //cout << cnt << endl;
    dfs1(n*m-1);
    //cout << cnt << endl;
    //cout << flag << endl;
    if(cnt || flag)
        cout << "No" << endl;
    else 
        cout << "Yes" << endl;
   
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
