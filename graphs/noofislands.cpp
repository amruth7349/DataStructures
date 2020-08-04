#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
#define pb push_back
vector<int> adj[10000];
bool visited[10000];
int ans;
void initialize()
{
    ans=0;
    for(int i=0;i<10000;i++)
    {
        adj[i].clear();
        visited[i]=false;
    }
}
void dfs(int s)
{
    //cout << adj[s].size() << endl;
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
            dfs(adj[s][i]);
    }
}
int findIslands(vector<int> a[], int n, int m) {
    initialize();
    int b[n*m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           // cout << a[i][j] << " ";
            b[i*m+j]=a[i][j];
            if(a[i][j]==0)
                continue;
            if(i+1<n && a[i+1][j]==1)
                adj[i*m+j].pb((i+1)*m+j);
            if(i-1>=0 && a[i-1][j]==1)
                adj[i*m+j].pb((i-1)*m+j);
            if(j+1<m && a[i][j+1]==1)
                adj[i*m+j].pb(i*m+j+1);
            if(j-1>=0 && a[i][j-1]==1)
                adj[i*m+j].pb(i*m+j-1);
            if(i+1<n && j+1<m && a[i+1][j+1]==1)
                adj[i*m+j].pb((i+1)*m+j+1);
            if(i+1<n && j-1>=0 && a[i+1][j-1]==1)
                adj[i*m+j].pb((i+1)*m+j-1);
            if(i-1>=0 and j-1>=0 && a[i-1][j-1]==1)
                adj[i*m+j].pb((i-1)*m+j-1);
            if(i-1>=0 && j+1<m and a[i-1][j+1]==1)
                adj[i*m+j].pb((i-1)*m+j+1);
        }
        //cout << endl;
    }
    for(int i=0;i<n*m;i++)
    {
        //cout << adj[i].size() << " ";
        if(!visited[i] && b[i]==1 )
        {
            //cout << i << " ";
            dfs(i);ans++;
        }
    }
    //cout << endl;
    return(ans);
}
