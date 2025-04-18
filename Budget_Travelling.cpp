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
#define F first
#define S second

int n, m, st, en, capacity;
unordered_map<int, vector<pair<int ,int>>>g;

vector<int>petrol;

vector<vector<int>>dist, visited;

int dij(int st, int en)
{
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>pq;
    pq.push({0,st,0});
    dist[st][0] = 0;
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int cost = top[0];
        int node = top[1];
        int fuel = top[2];

        if(visited[node][fuel]) continue;

        visited[node][fuel] = 1;

        if(capacity>fuel && dist[node][fuel+1] > cost + petrol[node])
        {
            dist[node][fuel+1] = cost + petrol[node];
            pq.push({dist[node][fuel+1], node, fuel+1});

        }

        for(auto nbr : g[node])
        {
            if(fuel>=nbr.S && dist[nbr.F][fuel - nbr.S] > cost)
            {
                dist[nbr.F][fuel - nbr.S] = cost;
                pq.push({dist[nbr.F][fuel - nbr.S], nbr.F, fuel - nbr.S});

            }
        }
    }

     int mini = 1e9;
    
    for (int i = 0; i <= capacity; i++)
    {
        mini = min(mini, dist[en][i]);
    }

    //assert(mini < 1e9);
    
    return mini;


}
void solve() {

    cin>>n;
    cin>>m;
    petrol.resize(n+10);

    for(int i = 0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;

        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }

    for(int i = 1;i<=n;i++)
    {
        int a;
        cin>>a;
        petrol[i] = a;
    }

    cin>>st>>en>>capacity;

    dist.resize(n+10, vector<int>(capacity+10, 1e9+2));
    visited.resize(n+10, vector<int>(capacity+10, 0));

    int ans = dij(st, en);
    cout<<ans<<endl;



  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    

    return 0;
}