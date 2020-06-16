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
ll parent[800],disc[800],low[800],tim,Caso;
vll adj[800];
bool visited[800];
vpll ans;
void initialize()
{
	ans.clear();
	tim=0;
	for(ll i=0;i<800;i++)
		adj[i].clear();
	for(ll i=0;i<800;i++)
	{
		visited[i]=false;
		parent[i]=i;
		disc[i]=0;
		low[i]=0;
	}
}
 
void find_brides(ll s)
{
	visited[s]=true;
	disc[s]=low[s]=tim++;
	ll child=0;
	for(ll i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
		{
			child++;
			parent[adj[s][i]]=s;
			find_brides(adj[s][i]);
			low[s]=std::min(low[s],low[adj[s][i]]);
			if(low[adj[s][i]]>disc[s])
				ans.pb({std::min(s,adj[s][i]),std::max(s,adj[s][i])});
		}
		else
		{
			if(parent[s]!=adj[s][i])
				low[s]=min(low[s],disc[adj[s][i]]);
		}
	}
}
 
void solve()
{
	initialize();
	ll n,m,i,p,q;
	cin >> n >> m;
	for(i=0;i<m;i++)
	{
		cin >> p >> q;
		adj[p].pb(q);
		adj[q].pb(p);
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]==false)
		{
			find_brides(i);
		}
	}
	
	cout << "Caso #" << ++Caso << endl;
	if(ans.size())
	{
		sort(ans.begin(),ans.end());
		cout << ans.size() << endl;
		for(i=0;i<ans.size();i++)
		{
			cout << ans[i].first << " " << ans[i].second << endl;
		}
	}
	else
	{
		cout << "Sin bloqueos" << endl;
	}
	
}
 
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}  
