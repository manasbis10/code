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

void dfs(int src, int par, map<int, vector<int>>&adj, vector<int>&dist,
map<pair<int, int>, int>&mp, int curr)
{
    for(auto nbr : adj[src])
    {
        if(nbr != par)
        {
            if(mp[{src, nbr}] < curr)
            {
                dist[nbr] = 1 + dist[src];
            }
            else dist[nbr] = dist[src];

            dfs(nbr, src, adj, dist, mp, mp[{src, nbr}]);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    map<int, vector<int>>adj;
    map<pair<int, int>, int>mp;

    for(int i = 0;i<n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}] = i+1;
        mp[{v, u}] = i+1;
    }
    vector<int>dist(n);

    dist[0] = 0;

    dfs(0, -1, adj, dist, mp, n);
    int ans = -1;
    for(auto i : dist)ans = max(ans, i);
    cout<<ans<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--) {
        solve();
    }

    return 0;
}