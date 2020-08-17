#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n,i,j,m=1;
    cin >> n;
    ll a[n],lis[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        lis[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[i])
                lis[i]=max(lis[i],lis[j]+1);
        }
        m=max(m,lis[i]);
    }
    cout << m << endl;
    
}

int main() {
	ll t;
	cin >> t;
	while(t--)
	    solve();
	return 0;
}