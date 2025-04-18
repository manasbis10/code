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
vector<int>g[200002];

int indp[200002];
int outdp[200002];



void dfs(int node, int parent)
{
	indp[node] = 0;

	for(auto v : g[node])
	{
		if(v != parent)
		{
			dfs(v, node);
			indp[node] = max(indp[node], 1 + indp[v]);
		}
	}
}

void dfs1(int node, int parent)
{
	int maxi1 = -1, maxi2 = -1;

	for(auto v : g[node])
	{
		if(v != parent)
		{
			if(indp[v]>=maxi1)
			{
				maxi2 = maxi1;
				maxi1 = indp[v];
			}
			else if(indp[v]>maxi2)
			{
				maxi2 = indp[v];
			}	
		}
		
	}

	for(auto v : g[node])
	{
		if(v != parent)
		{
			int t = maxi1;

			if(indp[v] == maxi1)
			{
				t = maxi2;
			}
			outdp[v] = max(1 + outdp[node], 2 + t);
			dfs1(v, node);


		}
	}
}


void solve() {
	int n;
	cin>>n;

	//outdp[0] = 0;

	for(int i = 0;i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}  

	dfs(1, 0);
	dfs1(1, 0);

	for(int i = 1;i<=n;i++)
	{
		cout<<max(indp[i], outdp[i])<<" ";
	}


}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

       solve();
    

    return 0;
}