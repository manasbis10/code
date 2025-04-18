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
int bfs(map<int, vector<int>>&adj, int start, int end)
{
    int n = adj.size();
    vector<int> distance(n+1, -1); 
    queue<int> q;
    
  
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (distance[neighbor] == -1) { 
                distance[neighbor] = distance[node] + 1;
                q.push(neighbor);
            }
        }
    }
    if(distance[end] != -1) return distance[end];
    return -1;

}
void solve() {
    int n, q;
    cin>>n>>q;
    map<int, vector<int>>g;

    for(int i =1 ;i<=n;i++)
    {
        int a;
        cin>>a;

        g[i];

        for(int j = 1;j<=a;j++)
        {
            g[i].push_back(i+j);
        }
    }
    while(q--)
    {
        int src, dest;
        cin>>src>>dest;

        int dist = bfs(g, src, dest);
        cout<<dist<<endl;
        continue;
    }
  

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
