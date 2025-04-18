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
int r, s;
int happiness[50][10];

int dp[50][(1<<10)];

int solve(int i, int mask)
{
    //base
    if(i == s) return 0;

    if(dp[i][mask] != -1) return dp[i][mask]; 

    int a = solve(i+1, mask);
    int b = -1;

    for(int j = 0;j<r;j++)
    {
        if(mask & (1<<j)) continue;
        b = max(b, solve(i+1, mask | (1<<j)) + happiness[i][j]);

    }

    return dp[i][mask] = max(a,b);

}

void solve() {
    
    cin>>r>>s;
    memset(dp, -1, sizeof(dp));

   // happiness.resize(s, vector<int>(r));

    for(int i = 0;i<s;i++)
    {
        for(int j = 0;j<r;j++) cin>>happiness[i][j];
    }

    int ans = solve(0,0);

    cout<<ans<<endl;
    

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