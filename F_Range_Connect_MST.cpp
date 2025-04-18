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
vector<pair<int, int>>g[200010];

void dfs(int src, vector<int>&visited)
{
    visited[src] = 1;
    for(auto v : g[src])
    {
        if(!visited[v.first])
        {
            dfs(src, visited);
        }
    }
}
struct UnionFind {
    vector<int> parent, rank;
    int components;

    UnionFind(int n) : components(n) {
        parent.resize(n);
        rank.resize(n, 1); 
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); 
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] >= rank[rootV]) {
                parent[rootV] = rootU;
                rank[rootU] += rank[rootV];
            } else {
                parent[rootU] = rootV;
                rank[rootV] += rank[rootU];
            }
            components--; 
        }
    }

    int getComponents() const {
        return components;
    }
};
void solve() {
    int n, m;
    cin>>n>>m;
    vector<array<int, 3>>edges;
    for(int i = 1;i<=m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        for(int k = u;k<=v;k++)
        {
            g[n+i].push_back({k, w});
            edges.push_back({w, n+i, k});
        } 

        
        
    }

    int cnt = 0;
    // vector<int>visited(200010, 0);
    // dfs(n+1, visited);
    // for(int i = 1;i<=n;i++)
    // {
    //     if(!visited[i])
    //     {
    //        cout<<-1<<endl;
    //        return;
    //     }
        
    // }

    sort(edges.begin(), edges.end());

    UnionFind uf(200010);

    int ans = 0;

    for(auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        if(uf.find(v) == uf.find(u)) continue;
        else
        {
            ans += w;
            uf.unionSets(u, v);
            
        }
    }
    cout<<ans<<endl;


  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   
        solve();
    

    return 0;
}