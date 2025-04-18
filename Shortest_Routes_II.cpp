#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9+7;
int mod_add(int a, int b, int m) {return (a % m + b % m) % m;}
int mod_mul(int a, int b, int m) {return (a % m * b % m) % m;}
int mod_sub(int a, int b, int m) {return ((a % m - b % m) + m) % m;}
int bin_exp(int base, int exp, int m) {
    if (exp == 0) return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0) {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) {return bin_exp(a, m - 2, m);}
/*---------------------------------------------------------------------------------------*/

void solve() {
  int n, m, q;
    cin>>n>>m>>q;

    map<int, vector<pair<int, int>>>g;

    for(int i = 0;i<m;i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        u--;
        v--;

        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    vector<vector<int>>dist(n, vector<int>(n, 1e16));

    for(int i =0;i<n;i++)
    {       
        dist[i][i] = 0;
         
    }

    for(int i = 0;i<n;i++)
    {
        for(auto k : g[i])
        {
            if(dist[i][k.first] > k.second)
            dist[i][k.first] = k.second;
        }
    }

    for(int via = 0;via<n;via++)
    {
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
            }
            
        }
    }

    while(q--)
    {
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        int ans = dist[u][v] == 1e16 ? -1 : dist[u][v];
        cout<<ans<<endl;
    }






}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
    

    return 0;
}