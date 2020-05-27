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

str a[200100];
bool visited[200100];
ll parent[200100];
vll adj[200100];

void initialize()
{
	for(ll i=0;i<200100;i++)
	{
		parent[i]=i;
		visited[i]=false;
	}
}

void dfs(ll s)
{
	visited[s]=true;
	for(ll i=0;i<adj[s].size();i++)
	{
		if(!visited[adj[s][i]])
			dfs(adj[s][i]);
	}
}
void solve()
{
	ll n,i,j;
	cin >> n;
	initialize();
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(i=0;i<n;i++)
	{
		for(char c:a[i])
		{
			adj[i].pb(n+c-'a');
			adj[n+c-'a'].pb(i);
		}
	}
	ll ans=0;
	for(i=n;i<n+26;i++)
	{
		if(!adj[i].empty() && !visited[i])
		{
			dfs(i);
			ans++;
		}
	}
	cout<< ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t=1;
    while(t--)
    	solve();
    return 0;
}
 
