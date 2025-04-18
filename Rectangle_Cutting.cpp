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

void solve() {
    
    int n, m;
    cin>>n>>m;

    vector<vector<int>>dp(n+1, vector<int>(m+1, 1e9));
    
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            //base case
            if(i==j)
            {
                dp[i][j] = 0;
                continue;
            }

            //horizontal cutting

            for(int h = 1 ; h<n;h++)
            {
                if(i>=h)
                dp[i][j] = min(dp[i][j], dp[i - h][j] + dp[h][j] + 1);
            }

            for(int v = 0 ; v<m;v++)
            {
                if(j>=v)
                dp[i][j] = min(dp[i][j], dp[i][j - v] + dp[i][v] + 1);
            }
        }
    }
    cout<<dp[n][m]<<endl;

}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}