#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vll vector<ll>
#define pb push_back
#define mll map<ll,ll>
#define vp vector< pair<ll,ll> >
#define mp make_pair
#define pll pair<ll,ll>
vll adj[1001];
bool visited[1001];
vll path,height;
void initialize()
{
    for(ll i=0;i<1001;i++)
    {
        adj[i].clear();
        visited[i]=false;
    }
    path.clear();
    height.clear();
}
void dfs(ll s,ll h)
{
    //cout << s << endl;
    visited[s]=true;
    path.pb(s);
    height.pb(h);
    for(ll i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
        {
            dfs(adj[s][i],h+1);
            path.pb(s);
            height.pb(h);
}

        }
    }
    
void solve(ll cas)
{
    initialize();
    ll n,i,p,q,j,query,left,right;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> p;
        for(j=0;j<p;j++)
        {
            cin >> q;
            adj[i+1].pb(q);
            adj[q].pb(i+1);
            //cout << i+1 << " " << q << endl;
        }
    }
    dfs(1,1);
    /*for(ll i=0;i<path.size();i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
     for(ll i=0;i<path.size();i++)
    {
        cout << height[i] << " ";
    }
    cout << endl;*/
    cin >> query;
    cout << "Case " << cas << ':' << endl;
    for(i=0;i<query;i++)
    {
        cin >> p >> q;
        for(j=0;j<path.size();j++)
        {
            if(path[j]==p)
            {
                left=j;
                break;
            }
        }
        for(j=0;j<path.size();j++)
        {
            if(path[j]==q)
            {
                right=j;
                break;
            }
        }
        //cout << left << " " << right << endl;
        if(left>right)
        {
            ll temp=right;right=left;left=temp;
        }
        //cout <<left <<" " << right << endl;
        ll m=100000,inx=-1;
        for(j=left;j<=right;j++)
        {
            if(height[j]<m)
            {
                m=height[j];
                inx=path[j];
            }
        }
        cout << inx << endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i=0;i<t;i++)
        solve(i+1);
}
