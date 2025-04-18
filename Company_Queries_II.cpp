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

vector<int>g[200001];
int depth[200001];

vector<vector<int>>parents;

void dfs(int node, int par)
{
	parents[0][node] = par;
	for(auto v : g[node])
	{
		if(v != par)
		{
			depth[v] = 1 + depth[node];
			dfs(v, node);
		}
	}

}

void preprocess(int n)
{
	for(int i = 1;i<21;i++)
	{
		for(int node = 0; node<n; node++)
		{
			int intermediate = parents[i-1][node];
			if(intermediate != -1)
			{
				parents[i][node] = parents[i-1][intermediate];
			}
		}
	}
}

int lca(int u, int v)
{
	int d1 = depth[u];
	int d2 = depth[v];

	
	if(d1 > d2)
	{
		int dist = d1 - d2;
		for(int i = 0; i<21 ;i++)
		{
			if(dist & (1<<i))
			{
				 u = parents[i][u];
			}
			if(u == -1) break;
		}
	}else if(d1 < d2)
	{
		int dist = d2 - d1;
		for(int i = 0; i<21 ;i++)
		{
			if(dist & (1<<i))
			{
				 v = parents[i][v];
			}
			if(v == -1) break;
		}

	}
	if(u == v) return u;

	for(int i = 20; i>=0; i--)
	{
		if(parents[i][u] != parents[i][v])
		{
			u = parents[i][u];
			v = parents[i][v];
		}
	}
	return parents[0][u];
}


void solve() {
	int n, q;
	cin>>n>>q;

	parents.resize(21, vector<int>(200001, -1));

	for(int i = 1;i<n;i++)
	{
		int u;
		cin>>u;
		u--;
		g[u].push_back(i);
	}
	depth[0] = 0;
	dfs(0, -1);
	//for(auto i : depth)cout<<i<<" ";
	preprocess(n);

	// for(int i = 0;i<21;i++)
	// {
	// 	for(int j = 0;j<n;j++) cout<<parents[i][j]<<" ";

	// 	cout<<endl;
	// }

	while(q--)
	{
		int a, b;
		cin>>a>>b;
		a--;b--;
		cout<<lca(a,b) + 1<<endl;
	}

  

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    

    return 0;
}