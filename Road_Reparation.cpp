#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int mod = 1e9 + 7;
int mod_add(int a, int b, int m) { return (a % m + b % m) % m; }
int mod_mul(int a, int b, int m) { return (a % m * b % m) % m; }
int mod_sub(int a, int b, int m) { return ((a % m - b % m) + m) % m; }
int bin_exp(int base, int exp, int m)
{
    if (exp == 0)
        return 1;
    int half = bin_exp(base, exp / 2, m);
    half = (half * half) % m;
    if (exp % 2 != 0)
    {
        half = (half * base) % m;
    }
    return half;
}
int mod_inv(int a, int m) { return bin_exp(a, m - 2, m); }
/*---------------------------------------------------------------------------------------*/
struct UnionFind
{
    vector<int> parent, rank;
    int components;

    UnionFind(int n) : components(n)
    {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] >= rank[rootV])
            {
                parent[rootV] = rootU;
                rank[rootU] += rank[rootV];
            }
            else
            {
                parent[rootU] = rootV;
                rank[rootV] += rank[rootU];
            }
            components--;
        }
    }

    int getComponents() const
    {
        return components;
    }
};

void solve()
{
    
    int n, m;
    cin >> n >> m;
   
    UnionFind uf(n);
 
    vector<array<int, 3>> adj(m);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        adj[i] = {c, a, b};
    }
    sort(adj.begin(), adj.end());

    int cost = 0;

    for (auto v : adj)
    {
        int c = v[0];
        int x = v[1];
        int y = v[2];

        if (uf.find(x) != uf.find(y))
        {
            cost += c;
            uf.merge(x, y);
        }
    }

    if(uf.getComponents() != 1)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout << cost << endl;
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}