#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 200005;

vector<int> pos[4][MAXN];
int sparse[4][MAXN][20];
int n, q;

int get_color(char c) {
    if (c == 'B') return 0;
    if (c == 'G') return 1;
    if (c == 'R') return 2;
    if (c == 'Y') return 3;
    return -1;
}

void build_sparse_table(int color) {
    for (int i = 0; i < pos[color][0].size(); i++) {
        sparse[color][i][0] = pos[color][0][i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < pos[color][0].size(); i++) {
            sparse[color][i][j] = min(sparse[color][i][j-1], sparse[color][i + (1 << (j-1))][j-1]);
        }
    }
}

int query(int color, int l, int r) {
    int j = log2(r - l + 1);
    return min(sparse[color][l][j], sparse[color][r - (1 << j) + 1][j]);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> q;
        vector<string> portals(n);
        
        for (int i = 0; i < n; i++) {
            cin >> portals[i];
            int c1 = get_color(portals[i][0]);
            int c2 = get_color(portals[i][1]);
            pos[c1][i].push_back(i);
            pos[c2][i].push_back(i);
        }
        
        for (int i = 0; i < 4; i++) {
            build_sparse_table(i);
        }

        while (q--) {
            int x, y;
            cin >> x >> y;
            x--; y--;

            int min_cost = INF;
            
            for (int i = 0; i < 4; i++) {
                if (!pos[i][x].empty() && !pos[i][y].empty()) {
                    min_cost = min(min_cost, abs(query(i, x, y)));
                }
            }

            if (min_cost == INF) cout << -1 << endl;
            else cout << min_cost << endl;
        }
        
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                pos[i][j].clear();
            }
        }
    }
    
    return 0;
}
