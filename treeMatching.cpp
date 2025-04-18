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

vector<int>g[200001];
int dp[200001][2];

void dfs(int node, int parent)
{
    dp[node][0] = dp[node][1] = 0;

    bool leaf = 1;

    for(auto v : g[node])
    {
        if(v != parent)
        {
            leaf = 0;
            dfs(v, node);
        }
    }
    if(leaf) return ;

    vector<int>pref, suff;

    for(auto v : g[node])
    {
        if(v != parent)
        pref.push_back(max(dp[v][1], dp[v][0]));
    }
    suff = pref;

    for(int i = 1;i<pref.size();i++) pref[i] += pref[i-1];
    for(int i = suff.size()-2;i>=0;i--) suff[i] += suff[i+1];

    dp[node][0] = suff[0];

    int child = 0;
    
    for(auto v : g[node])
    {
        if(v == parent) continue;
        int p_sum = child == 0 ? 0 : pref[child-1];
        int s_sum = child == (int)suff.size()-1 ? 0 : suff[child + 1];
        dp[node][1] = max(dp[node][1], 1 + p_sum + s_sum + dp[v][0]);
        child++;
    }
}

void solve() {
    int n;
    cin>>n;

    for(int i = 0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);
    cout<<max(dp[1][0], dp[1][1])<<endl;



  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}