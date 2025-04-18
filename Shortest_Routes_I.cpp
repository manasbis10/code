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
vector<int> dij(int src, map<int, vector<pair<int, int>>>&g, int n)
{
    vector<int>visited(n, 0);
    vector<int>dist(n,1e15);

    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

    pq.push({0, src});
    //visited[src] = 1;
    dist[src] = 0;
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int node = top.second;
        int wt = top.first;

        if(visited[node]) continue;
        else visited[node] = 1;

        for(auto v : g[node])
        {
            if(dist[v.first] > wt + v.second)
            {
                dist[v.first] = wt + v.second;
                pq.push({ wt + v.second, v.first});
            }
        }
    }
    return dist;


}
void solve() {
    int n, m;
    cin>>n>>m;

    map<int, vector<pair<int, int>>>g;

    for(int i = 0;i<m;i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        u--;
        v--;

        g[u].push_back({v, wt});
    }
    vector<int>ans = dij(0, g, n);
    for(auto i : ans)cout<<i<<" ";
   
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    
        solve();
    

    return 0;
}