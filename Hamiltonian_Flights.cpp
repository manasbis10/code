#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int mod = 1e9 + 7;

vector<int> g[20];
int n, m;
int dp[20][1 << 20];

int dfs(int node, int mask) {
    if (mask == (1 << n) - 1) {
        return (node == n - 1) ? 1 : 0;
    }
    if(node == n-1) return 0;

    if (dp[node][mask] != -1) {
        return dp[node][mask];
    }
    int ans = 0;

    for (auto v : g[node]) {
        if (!(mask & (1 << v))) {
            ans = (ans + dfs(v, mask | (1 << v)))%mod;
        }
    }

    return dp[node][mask] = ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }

    memset(dp, -1, sizeof(dp));

    int ans = dfs(0, 1);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

  
        solve();
    

    return 0;
}
