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
int dp[200001];
vector<int>g[200001];

void dfs(int node, int parent)
{
    for(auto v : g[node])
    {
        if(v != parent)
        {
            dp[v] = !dp[node];
            dfs(v,node);
        }
    }

}

void dfs1(int node, int parent)
{
    bool child = 0;
    for(auto v : g[node])
    {
        if(v != parent)
        {
            child = 1;
            dp[v] = 1;
            dfs1(v, node);
        }
    }
    if(child==0) dp[node] = 0;

}

void solve() {
    int n,t ;
    cin>>n>>t;

    for(int i = 0;i<n-1;i++)
    {
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    int node = -1;
    for(int i = 1;i<=n;i++)
    {
        if(g[i].size() == 1)
        {
            node = i;
            break;
        }
    }
    dp[node] = 0;

    if(n&1)
        dfs(node, 0);
    if(n %2 == 0)
    {
        dfs1(node, 0);
    }
    while(t--)
    {
        int src;
        cin>>src;

        if(dp[src] == 1)
        {
            cout<<"Ron"<<endl;
        }
        else
        {
            cout<<"Hermione"<<endl;
        }
    }



  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
        solve();
    

    return 0;
}