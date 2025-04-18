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
vector<int>parent;
vector<int>visited;

int sp = 0, ep =0;

bool dfs(int node, int par, vector<vector<int>>&g)
{
    visited[node] = 1;
    parent[node] = par;

    for(auto v : g[node])
    {
        if(!visited[v])
        {
            if(dfs(v, node, g)) return true;
        }
        else if(v != par)
        {
            sp =  v;
            ep = node;
            return true;
        }
    }
    return false;
}

bool visit_all(int n,  vector<vector<int>>&g)
{
	for(int i = 1; i <= n; ++i)
	{
		if(!visited[i])
			if(dfs(i,0, g)) return true;
	}
	return false;
}

void solve() {

    int n, m;
    cin>>n>>m;
    parent.resize(n+1);
    visited.resize(n+1);

    vector<vector<int>>g(n+1);

    for(int i = 0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(!visit_all(n , g))
    {
        cout<<"IMPOSSIBLE"<<endl;
        return ;
    }
   
            
    vector<int>path;
    int ini = ep;
    while(sp != ep)
    {
        path.push_back(ep);
        ep = parent[ep];
    }
    path.push_back(sp);
    path.push_back(ini);
    cout<<path.size()<<endl;
    for(auto i: path) cout<<i<<" ";
    return ;
        
    
    


  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    

    return 0;
}