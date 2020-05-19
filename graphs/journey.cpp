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


bool visited[100001];
vll adj[100001];
long db ans=0;
long db prob[100001];
long db dist[100001];

void initialize()
{
    for(ll i=0;i<100;i++)
    {
        visited[i]=false;
        adj[i].clear();
        dist[i]=1.0;
    }
}

void bfs(ll s)
{
    visited[s]=true;
    prob[s]=1.0;
    list<ll> q;
    q.pb(s);
    ll i;
    while(!q.empty())
    {
        s=q.front();
        q.pop_front();
        long db c=0;
        for(i=0;i<adj[s].size();i++)
        {
            if(visited[adj[s][i]]==false)
                c++;
        }
        long db k=prob[s]/c;
        if((adj[s].size()==1) && s!=1)
            ans+=prob[s]*dist[s];
        for(i=0;i!=adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]]=true;
                prob[adj[s][i]]=k;
                q.pb(adj[s][i]);
                dist[adj[s][i]]=dist[s]+1;
            }
        }
       
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll nodes,edges,p,q;
    cin >> nodes;
    for(ll i=0;i<nodes-1;i++)
    {
        cin >> p >> q;
        adj[p].pb(q);
        adj[q].pb(p);
    }
    prob[1]=1;
    bfs(1);
    cout << fixed << setprecision(7) <<  ans << endl;
    return 0;
}