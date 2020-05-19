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
 
char a[1000][1000];
ll b[1000][1000];
vll adj[1000000];
bool visited[1000000];
 
 
void bfs(ll s)
{
    visited[s]=true;
    list<ll> q;
    q.pb(s);
    ll i;
    while(!q.empty())
    {
        s=q.front();
        q.pop_front();
        for(i=0;i!=adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]]=true;
                q.pb(adj[s][i]);
            }
        }
       
    }
    
}
 
void solve()
{
    ll n,i,j;
    cin >> n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin >> a[i][j];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ll p=i*n;
            if(a[i][j]=='#')
            {
                b[i][j]=0;
                continue;
            }
            if(i==0 && j==0)
            {
               b[i][j]=1;
            }
            else if(i==0)
            {
                b[i][j]=b[i][j-1];
                adj[p+j].pb(p+j-1);
                adj[p+j-1].pb(p+j);
                
            }
            else if(j==0)
            {
                b[i][j]=b[i-1][j];
                adj[p+j-n].pb(p+j);
                adj[p+j].pb(p+j-n);
            }
            else 
            {
                b[i][j]=(b[i-1][j]%2147483647+b[i][j-1]+2147483647)%2147483647;
                adj[p+j-n].pb(p+j);
                adj[p+j].pb(p+j-n);
                adj[p+j].pb(p+j-1);
                adj[p+j-1].pb(p+j);
            }
            visited[p+j]=false;
        }
    }
    bfs(0);
    if(b[n-1][n-1])
        cout << b[n-1][n-1] << endl;
    else if(visited[n*n-1])
        cout << "THE GAME IS A LIE" << endl;
    else
        cout << "INCONCEIVABLE" << endl;
}
 
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t;
    t=1;
    while(t--)
        solve();
 
    return 0;
} 