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
int inf = -1e17;
void solve() {

    int n, m;
    cin>>n>>m;

    vector<array<int, 3>>g;

   

    for(int i = 0;i<m;i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;

        g.push_back({u, v, -wt});
    }

     if(m == 1 && g[0][0] == g[0][1])
    {
        if(-g[0][2]>=0)
        {cout<<-1<<endl;
        return;}
        else
        cout<<0<<endl;
        return;
    }

    if(m == 2)
    {
        if(g[0][0] == g[0][1])
        {
            cout<<-1<<endl;
            return;
        }
    }

    vector<int>dist(n + 1, 1e17);
    dist[1] = 0;

    for(int i = 0;i<n-1;i++)
    {
        for(auto k : g)
        {
            int u = k[0];
            int v = k[1];
            int wt = k[2];

            if(dist[u] != 1e17 && dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(int i = 0;i<n-1;i++)
    {
        for(auto k : g)
        {
            int u = k[0];
            int v = k[1];
            int wt = k[2];

            if(dist[u] != 1e17 && dist[v] > dist[u] + wt)
            {
                dist[v] = inf;
            }
        }
    }
   
    if(dist[n] == inf)
    {
        cout<<-1<<endl;
        return;
    }
    

    
    cout<<dist[n]*-1<<endl;
  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

 
        solve();
    

    return 0;
}